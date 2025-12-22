// Qs: C_Even_Positions
// Time: 08:33:15

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'

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
        vl openbr, closbr;
        openbr.pb(0);
        ll ctr = 1;
        s[0] = '(';
        f(1,s.size())
        {
            if (s[i] == '(')
            {
                ctr++;
                openbr.pb(i);
            }
            else if (s[i] == ')')
            {
                ctr--;
                closbr.pb(i);
            }
            else
            {
                if (ctr > 0)
                {
                    s[i] = ')';
                    ctr--;
                    closbr.pb(i);
                }
                else
                {
                    s[i] = '(';
                    ctr++;
                    openbr.pb(i);
                }
            }
        }
        ll cost = 0;
        f(0,n/2) cost+=closbr[i]-openbr[i];
        cout<<cost<<nl;
    }
    return 0;
}