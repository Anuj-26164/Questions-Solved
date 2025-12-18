// Qs: B_AND_Reconstruction
// Time: 15:46:44

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
        bool flag = true;
        ll n;
        cin >> n;
        vl arrb(n - 1);
        for (auto &c : arrb)
            cin >> c;
        vl arra(n);
        arra[0] = arrb[0];
        arra[n - 1] = arrb[n - 2];
        for (int i = 1; i < n - 1; i++)
        {
            arra[i] = (arrb[i - 1] | arrb[i]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (arrb[i] != (arra[i] & arra[i + 1]))
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (auto &c : arra)
            {
                cout << c << " ";
            }
            cout << nl;
        }
        else
        {
            cout << -1 << nl;
        }
    }
    return 0;
}