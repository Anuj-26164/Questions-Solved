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
    int ans(int idx, int n, vector<int> &arr, vector<int> &dp)
    {
        if (idx >= n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        return dp[idx] = max(arr[idx] + ans(idx + 2, n, arr, dp), ans(idx + 1, n, arr, dp));
    }
    int findMaxSum(vector<int> &arr)
    {
        int n = arr.size();
        if(n==1)
            return arr[0];
        vector<int> dp(n);
        // return ans(0, n, arr, dp);
        vector<vector<int>> dp(n);
        // dp(i) stores max loot till ith index
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
};
