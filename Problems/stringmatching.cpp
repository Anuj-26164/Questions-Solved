#include <bits/stdc++.h>
using namespace std;
#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define int long long
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
#define debug(x) cerr << #x << " = " << x << nl;
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size(), p = 31;
        vector<int> hash(n + 1, 0), ppow(n + 1, 1);
        hash[0] = 0;
        for (int i = 1; i < n; i++)
            ppow[i] = (ppow[i - 1] * p) % MOD;
        for (int i = 0; i < n; i++)
            hash[i + 1] = (hash[i] + (s[i] - 'a' + 1) * ppow[i]) % MOD;

        for (int len = 1; len <= n / 2; len++)
        {
            bool ok = true;
            if (n % len != 0)
                continue;
            int base_hash = hash[len];

            for (int i = len; i < n; i += len)
            {
                int curr_hash = hash[i + len] - hash[i];
                if (curr_hash != base_hash * ppow[i])
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
                return true;
        }
        return false;
    }
};
