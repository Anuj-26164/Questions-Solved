// Qs: B_Having_Been_a_Treasurer_in_the_Past_I_Help_Goblins_Deceive
// Time: 20:21:48

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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll cntu = 0, cntm = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '_')
                cntm++;
            else
                cntu++;
        }
        if(cntu&1)
        {
            ll x=cntu/2;
            ll y=cntu/2+1;
            cout<<x*y*cntm<<nl;
        }
        else 
        {
            cout<<cntu*cntu*cntm/4<<nl;
        }
    }
    return 0;
}