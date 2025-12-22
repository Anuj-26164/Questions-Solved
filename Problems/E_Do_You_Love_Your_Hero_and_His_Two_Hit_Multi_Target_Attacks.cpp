// Qs: E_Do_You_Love_Your_Hero_and_His_Two_Hit_Multi_Target_Attacks
// Time: 21:51:54

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'
#define vin(v, n) \
    vl v(n);      \
    for (0, n)    \
        cin >> v[i];

void yes()
{
    cout << "YES" << endl;
}

void no()
{
    cout << "NO" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll k;
        cin >> k;
        cout << 2*k << nl;
        for (int i = 0; i < k; i++)
        {
            cout << 2 * i << " " << i << nl;
            cout << 2 * i + 1 << " " << i << nl;
        }
    }
    return 0;
}