#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define ll long long
#define f(i, k, n) for (int i = k; i < n; i++)
#define nl endl
#define vin(v, n)               \
    vl v(n);                    \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> v[i];            \
    }
#define vout(v, i, k, n)            \
    do                              \
    {                               \
        for (int i = k; i < n; i++) \
            cout << v[i] << " ";    \
        cout << "\n";               \
    } while (0)
#define ff first
#define ss second
#define MOD 1000000007LL
const ll INF = 4e18;
template <class T, class Container = vector<T>>
using maxheap = priority_queue<T, Container, less<T>>;
template <class T, class Container = vector<T>>
using minheap = priority_queue<T, Container, greater<T>>;
#define DP1(v, n) vector<long long> v((n) + 1, -1)
#define DP2(v, n, m) vector<vector<long long>> v((n) + 1, vector<long long>((m) + 1, -1))
#define pll pair<long long, long long>

class Solution
{
public:
    int n, m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int dfs(vector<vector<int>> &a, int x, int y, int xd, int yd)
    {
        if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] == 0)
            return -1000000000;

        if (x == xd && y == yd)
            return 0;

        a[x][y] = 0; 

        int best = -1000000000;
        for (int d = 0; d < 4; d++)
        {
            best = max(best, dfs(a, x + dx[d], y + dy[d], xd, yd));
        }

        a[x][y] = 1; 

        if (best < 0)
            return best;
        return 1 + best;
    }

    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        n = matrix.size();
        m = matrix[0].size();

        if (matrix[xs][ys] == 0 || matrix[xd][yd] == 0)
            return -1;

        int ans = dfs(matrix, xs, ys, xd, yd);
        return (ans < 0 ? -1 : ans);
    }
};
