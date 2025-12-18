// Qs: B_250_Thousand_Tons_of_TNT
// Time: 19:14:37

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl vec(n);
        for (auto &c : vec)
            cin >> c;
        set<ll> differences;
        vector<ll> prefix(n + 1, 0);
        for (int j = 1; j <= n; j++)
        {
            prefix[j] = prefix[j - 1] + vec[j - 1];
        }
        
    }
    return 0;
}