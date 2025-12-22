#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define ll long long int
#define nl '\n'

const long long MOD = 998244353;

// factorial modulo MOD
long long factorial_mod(long long n)
{
    long long res = 1;
    for (long long i = 1; i <= n; i++)
        res = (res * i) % MOD;
    return res;
}

void solve()
{
    string s;
    cin >> s;
    vl v; // will store block lengths minus 1
    int i = 0;

    while (i < s.size())
    {
        int cnt = 1;
        while (i + 1 < s.size() && s[i + 1] == s[i])
        {
            cnt++;
            i++;
        }
        v.push_back(cnt); // store full block length, not cnt-1
        i++;
    }

    int totalRemovals = accumulate(all(v), 0LL) - v.size(); // sum of (cnt-1)
    long long totalWays = 1;

    // multiply block lengths
    for (auto len : v)
        totalWays = (totalWays * len) % MOD;

    // multiply by factorial of total removals
    totalWays = (totalWays * factorial_mod(totalRemovals)) % MOD;

    cout << totalRemovals << " " << totalWays << nl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
