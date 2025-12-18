# main.py
import sys
import random
import pygame

# --- Config ---
WIDTH, HEIGHT = 900, 500
FPS = 60
PADDLE_W, PADDLE_H = 10, 90
BALL_SIZE = 12
PADDLE_SPEED = 6
BALL_SPEED_START = 5
FONT_NAME = None

# --- Init ---
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Pong — Starter")
clock = pygame.time.Clock()
font = pygame.font.SysFont(FONT_NAME, 28)

# --- Game objects ---
class Paddle:
    def __init__(self, x, y):
        self.rect = pygame.Rect(x, y, PADDLE_W, PADDLE_H)
        self.speed = 0

    def move(self, dy):
        self.rect.y += dy
        self.rect.y = max(0, min(HEIGHT - PADDLE_H, self.rect.y))

    def update(self):
        self.move(self.speed)

    def draw(self, surf):
        pygame.draw.rect(surf, (230,230,230), self.rect)

class Ball:
    def __init__(self):
        self.rect = pygame.Rect(WIDTH//2 - BALL_SIZE//2, HEIGHT//2 - BALL_SIZE//2, BALL_SIZE, BALL_SIZE)
        self.reset()

    def reset(self, serve_left=None):
        self.rect.center = (WIDTH//2, HEIGHT//2)
        angle = random.uniform(-0.4, 0.4)
        direction = -1 if (serve_left is True) else (1 if serve_left is False else random.choice([-1,1]))
        speed = BALL_SPEED_START
        self.vx = direction * speed
        self.vy = speed * angle

    def update(self):
        self.rect.x += int(self.vx)
        self.rect.y += int(self.vy)

        # top/bottom bounce
        if self.rect.top <= 0 or self.rect.bottom >= HEIGHT:
            self.vy = -self.vy

    def draw(self, surf):
        pygame.draw.ellipse(surf, (230,230,230), self.rect)

# --- Helpers ---
def draw_center_text(surf, text, y, size=36):
    f = pygame.font.SysFont(FONT_NAME, size)
    r = f.render(text, True, (200,200,200))
    rect = r.get_rect(center=(WIDTH//2, y))
    surf.blit(r, rect)

# --- Game State ---
left = Paddle(10, HEIGHT//2 - PADDLE_H//2)
right = Paddle(WIDTH - 10 - PADDLE_W, HEIGHT//2 - PADDLE_H//2)
ball = Ball()
score_left = 0
score_right = 0
ai_mode = False
paused = False
state = "menu"  # "menu", "playing", "gameover"

WINNING_SCORE = 7

# --- Simple AI for a paddle ---
def ai_move(paddle: Paddle, ball: Ball):
    # Move paddle towards ball center with some smoothing
    target = ball.rect.centery
    if paddle.rect.centery < target - 10:
        paddle.move(PADDLE_SPEED - 1)
    elif paddle.rect.centery > target + 10:
        paddle.move(-(PADDLE_SPEED - 1))

# --- Main loop ---
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        if event.type == pygame.KEYDOWN:
            if state == "menu":
                if event.key == pygame.K_1:
                    ai_mode = False
                    score_left = score_right = 0
                    ball.reset()
                    state = "playing"
                elif event.key == pygame.K_2:
                    ai_mode = True
                    score_left = score_right = 0
                    ball.reset(serve_left=False)
                    state = "playing"
                elif event.key == pygame.K_ESCAPE:
                    pygame.quit(); sys.exit()
            elif state == "playing":
                if event.key == pygame.K_p:
                    paused = not paused
                if event.key == pygame.K_ESCAPE:
                    state = "menu"
            elif state == "gameover":
                if event.key == pygame.K_RETURN:
                    state = "menu"

        # paddle controls
        # left: w/s
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_w:
                left.speed = -PADDLE_SPEED
            if event.key == pygame.K_s:
                left.speed = PADDLE_SPEED
            if not ai_mode:
                if event.key == pygame.K_UP:
                    right.speed = -PADDLE_SPEED
                if event.key == pygame.K_DOWN:
                    right.speed = PADDLE_SPEED

        if event.type == pygame.KEYUP:
            if event.key in (pygame.K_w, pygame.K_s):
                left.speed = 0
            if event.key in (pygame.K_UP, pygame.K_DOWN):
                right.speed = 0

    # Update
    if state == "playing" and not paused:
        left.update()
        if ai_mode:
            # right is AI
            ai_move(right, ball)
            right.update()
        else:
            right.update()

        ball.update()

        # collisions with paddles
        if ball.rect.colliderect(left.rect):
            ball.rect.left = left.rect.right
            ball.vx = -ball.vx * 1.03  # speed up slightly
            # small deflection based on hit point
            offset = (ball.rect.centery - left.rect.centery) / (PADDLE_H/2)
            ball.vy += offset * 2

        if ball.rect.colliderect(right.rect):
            ball.rect.right = right.rect.left
            ball.vx = -ball.vx * 1.03
            offset = (ball.rect.centery - right.rect.centery) / (PADDLE_H/2)
            ball.vy += offset * 2

        # scoring
        if ball.rect.left <= 0:
            score_right += 1
            ball.reset(serve_left=False)
        if ball.rect.right >= WIDTH:
            score_left += 1
            ball.reset(serve_left=True)

        # check win
        if score_left >= WINNING_SCORE or score_right >= WINNING_SCORE:
            state = "gameover"

    # Draw
    screen.fill((10, 10, 20))
    # center line
    for y in range(0, HEIGHT, 24):
        pygame.draw.rect(screen, (50,50,50), (WIDTH//2 - 2, y, 4, 12))

    left.draw(screen)
    right.draw(screen)
    ball.draw(screen)

    # HUD
    sc_left_surf = font.render(str(score_left), True, (200,200,200))
    sc_right_surf = font.render(str(score_right), True, (200,200,200))
    screen.blit(sc_left_surf, (WIDTH//4 - sc_left_surf.get_width()//2, 20))
    screen.blit(sc_right_surf, (3*WIDTH//4 - sc_right_surf.get_width()//2, 20))

    if state == "menu":
        draw_center_text(screen, "Pong — Starter", HEIGHT//2 - 60, size=48)
        draw_center_text(screen, "1) Two-player  2) Play vs AI", HEIGHT//2, size=28)
        draw_center_text(screen, "Press ESC to quit", HEIGHT//2 + 50, size=20)
    elif state == "gameover":
        winner = "Left" if score_left > score_right else "Right"
        draw_center_text(screen, f"Game Over — {winner} wins!", HEIGHT//2 - 20, size=34)
        draw_center_text(screen, "Press Enter to return to menu", HEIGHT//2 + 30, size=22)
    elif state == "playing" and paused:
        draw_center_text(screen, "Paused — press P to resume", HEIGHT//2, size=28)

    # instructions
    instr = "W/S = Left | Up/Down = Right | P = Pause | ESC = Menu"
    instr_surf = pygame.font.SysFont(FONT_NAME, 16).render(instr, True, (120,120,120))
    screen.blit(instr_surf, (WIDTH//2 - instr_surf.get_width()//2, HEIGHT - 30))

    pygame.display.flip()
    clock.tick(FPS)
