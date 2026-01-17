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
    vector<int> search(string pat, string txt)
    {
        int n = txt.size(), m = pat.size(), p = 31;
        if (m > n)
            return {};
        vector<ll> ppow(n, 1);
        f(i, 1, n) ppow[i] = (ppow[i - 1] * p) % MOD;
        ll base_hash = 0, curr_hash = 0;
        f(i, 0, m) base_hash = (base_hash + (txt[i] - 'a' + 1) * ppow[i]) % MOD;
        f(i, 0, m) curr_hash = (curr_hash + (pat[i] - 'a' + 1) * ppow[i]) % MOD;
        vector<int> ans;
        if (base_hash == curr_hash)
            ans.emplace_back(0);
        f(i, 1, i + m - 1 < n)
        {
            curr_hash = ((curr_hash - ((txt[i - 1] - 'a' + 1) * ppow[i - 1]) + MOD) % MOD);
            curr_hash = ((curr_hash + ((txt[i + m - 1] - 'a' + 1) * ppow[i + m - 1]) + MOD) % MOD);
            if (curr_hash == (base_hash)*ppow[i])
                ans.emplace_back(i);
        }
        return ans;
    }
};
