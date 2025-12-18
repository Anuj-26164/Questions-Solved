#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> grid, moveDir;
vector<vector<int>> visited;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char dir[4] = {'U', 'L', 'D', 'R'};

bool isValid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y] != '#');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    visited.assign(n, vector<int>(m, 0));
    moveDir.assign(n, vector<char>(m, 0));

    pair<int, int> start, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                start = {i, j};
            if (grid[i][j] == 'B')
                end = {i, j};
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (isValid(nx, ny))
            {
                visited[nx][ny] = 1;
                moveDir[nx][ny] = dir[k]; // store how we entered
                q.push({nx, ny});
            }
        }
    }

    if (!visited[end.first][end.second])
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    // reconstruct path
    string path = "";
    pair<int, int> cur = end;
    while (cur != start)
    {
        char d = moveDir[cur.first][cur.second];
        path += d;
        // move backwards
        if (d == 'U')
            cur.first += 1;
        if (d == 'D')
            cur.first -= 1;
        if (d == 'L')
            cur.second += 1;
        if (d == 'R')
            cur.second -= 1;
    }

    reverse(path.begin(), path.end());
    cout << path.size() << "\n"
         << path << "\n";
}
