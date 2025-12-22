// Qs: B_Cost_of_the_Array
// Time: 09:52:16

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
    vl v;         \
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
        bool possible = false;
        ll n, k;
        cin >> n >> k;
        vl vec(n + 1);
        vec[0] = -1;
        f(1, n + 1) cin >> vec[i];
        int ctr = 1;
        for (int i = 2; i <= k / 2; i += 2)
        {
            ll x = accumulate(vec.begin() + i, vec.begin() + (n - k + i), 0LL);
            if (x > (n - k + 1) * ctr)
            {
                possible = true;
                break;
            }
            else
            {
                ctr++;
            }
        }
        if (!possible)
            cout << n + 1;
        else
            cout << ctr;
        cout<<nl;
    }
    return 0;
}