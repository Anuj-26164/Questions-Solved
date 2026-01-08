// Qs: Monsters
// Time: 15:57:26

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define int long long
#define ll long long
#define f(i, k, n) for (int i = k; i < n; i++)
#define nl '\n'
#define vin(v, n)               \
    vl v(n);                    \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> v[i];            \
    }
#define vout(v, n)                  \
    do                              \
    {                               \
        for (int i = 0; i < n; i++) \
            cout << v[i] << " ";    \
        cout << "\n";               \
    } while (0)
#define ff first
#define ss second
#define DP1(v, n) vector<long long> v((n) + 1, -1)
#define DP2(v, n, m) vector<vector<long long>> v((n) + 1, vector<long long>((m) + 1, -1))
#define pll pair<long long, long long>
#define debug(x) cerr << #x << " = " << x << nl;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (size_t i = 0; i < v.size(); i++)
        os << (i ? ", " : "") << v[i];
    return os << "]";
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
ostream &operator<<(ostream &os, const set<T> &s)
{
    os << "{";
    bool f = true;
    for (auto &x : s)
        os << (f ? "" : ", ") << x, f = false;
    return os << "}";
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &m)
{
    os << "{";
    bool f = true;
    for (auto &x : m)
        os << (f ? "" : ", ") << x, f = false;
    return os << "}";
}

void yes()
{
    cout << "YES" << endl;
}

void no()
{
    cout << "NO" << endl;
}

int msb(int mask)
{
    if (mask == 0)
        return -1;
    return 63 - __builtin_clzll(mask);
}
#define lsb(mask) __builtin_ctzll(mask) /// 0 -> 64
#define cntsetbit(mask) __builtin_popcountll(mask)
#define checkbit(mask, bit) ((mask >> bit) & 1ll)
#define onbit(mask, bit) ((mask) | (1LL << (bit)))
#define offbit(mask, bit) ((mask) & ~(1LL << (bit)))
#define changebit(mask, bit) ((mask) ^ (1LL << bit))

// const int N = 1001, M = 11, MOD = 1e9 + 7;
ll n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char dir[4] = {'U', 'R', 'D', 'L'};
vector<vector<char>> grid;
bool ispossible(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && grid[x][y] != 'M');
}

void solve()
{
    cin >> n >> m;
    int startx, starty;
    queue<pair<int, int>> q;
    grid.assign(n, vector<char>(m));
    vector<vector<int>> mdist(n, vector<int>(m, INT_MAX));
    vector<vector<int>> adist(n, vector<int>(m, INT_MAX));
    vector<vector<char>> par(n, vector<char>(m, 'x'));
    f(i, 0, n)
    {
        f(j, 0, m)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                adist[i][j] = 0;
                startx = i, starty = j;
            }
            if (grid[i][j] == 'M')
            {
                mdist[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        f(i, 0, 4)
        {
            int newx = x + dx[i], newy = y + dy[i];
            if (ispossible(newx, newy) && mdist[newx][newy] == INT_MAX)
            {
                mdist[newx][newy] = mdist[x][y] + 1;
                q.emplace(newx, newy);
            }
        }
    }
    q.emplace(startx, starty);
    pair<int, int> dest = {-1, -1};
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if ((x == 0 || x == n - 1 || y == 0 || y == m - 1) && mdist[x][y] > adist[x][y]) // target reached
        {
            dest.first = x, dest.second = y;
            break;
        }
        f(i, 0, 4)
        {
            int newx = x + dx[i], newy = y + dy[i];
            if (ispossible(newx, newy) && adist[newx][newy] == INT_MAX && adist[x][y] + 1 < mdist[newx][newy])
            {
                par[newx][newy] = dir[i];
                adist[newx][newy] = adist[x][y] + 1;
                q.emplace(newx, newy);
            }
        }
    }
    if (dest.first == -1 && dest.second == -1)
    {
        cout << "NO";
        return;
    }
    else // constructing answer
    {
        string ans = "";
        int x = dest.first, y = dest.second;
        while (!(x == startx && y == starty))
        {
            char c = par[x][y];
            ans.push_back(c);

            if (c == 'L')
                y++;
            else if (c == 'R')
                y--;
            else if (c == 'U')
                x++;
            else if (c == 'D')
                x--;
        }
        reverse(all(ans));
        cout << "YES" << nl;
        cout << ans.size() << nl;
        cout << ans << nl;
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    {
        solve();
    }
    return 0;
}