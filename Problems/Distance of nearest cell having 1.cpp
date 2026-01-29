#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define int long long
#define ll long long
#define f(i,k,n) for(int i=k;i<n;i++)
#define nl endl
#define vin(v, n) vl v(n); for (int i = 0; i < n; i++) {cin>>v[i];}
#define vout(v,i,k,n) do { for (int i = k; i < n; i++) cout << v[i] << " "; cout << "\n"; } while(0)
#define ff first
#define ss second
#define MOD 1000000007LL
const ll INF = 4e18;
template<class T, class Container = vector<T>>
using maxheap = priority_queue<T, Container, less<T>>;
template<class T, class Container = vector<T>>
using minheap = priority_queue<T, Container, greater<T>>;
#define DP1(v, n) vector<long long> v((n)+1, -1)
#define DP2(v, n, m) vector<vector<long long>> v((n)+1, vector<long long>((m)+1, -1))
#define pll pair<long long,long long>

class Solution
{
public:
    vector<vector<int>> nearestOne(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(m, INF));

        // Initialization
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    dist[i][j] = 0;
            }
        }

        // First pass: top-left to bottom-right
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i > 0)
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                if (j > 0)
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
            }
        }

        // Second pass: bottom-right to top-left
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i < n - 1)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j < m - 1)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }

        return dist;
    };
