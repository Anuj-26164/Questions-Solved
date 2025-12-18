// Qs: A_Cut_the_Array
// Time: 20:08:13

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
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

void solve()
{
    ll n;
    cin >> n;
    vl v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vl prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + v[i];

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sumx = prefix[i] % 3;
            int sumy = (prefix[j] - prefix[i]) % 3;
            int sumz = (prefix[n] - prefix[j]) % 3;

            if ((sumx == sumy && sumy == sumz) ||
                (sumx != sumy && sumy != sumz && sumx != sumz))
            {
                cout << i << " " << j << nl;
                return;
            }
        }
    }
    cout << 0 << " " << 0 << nl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}