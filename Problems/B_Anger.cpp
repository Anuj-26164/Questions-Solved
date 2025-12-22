// Qs: B_Anger
// Time: 15:17:07

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
bool isOdd(ll n)
{
    return n & 1;
}
ll computePhi(ll n)
{
    ll result = n;
    if (n % 2 == 0)
    {
        while (n % 2 == 0)
            n /= 2;
        result -= result / 2;
    }
    for (ll p = 3; p * p <= n; p += 2)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
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
        if (n == 2)
            cout << "ALICE" << nl;
        else
        {
            ll z = computePhi(n);
            ll alice = 0, bob = 0;
            if (isOdd(z) && isOdd(n - z))
            {
                alice += (z + 1) / 2;
                bob += z - alice;
                alice += (n - z - 1) / 2;
                bob += (n - z + 1) / 2;
            }
            else if (!isOdd(z) && isOdd(n - z))
            {
                bob += z / 2;
                alice += z / 2;
                alice += (n - z + 1) / 2;
                bob += (n - z - 1) / 2;
            }
            else if (isOdd(z) && !isOdd(n - z))
            {
                alice += (z + 1) / 2;
                bob += z - alice;
                alice += (n - z) / 2;
                bob += (n - z) / 2;
            }
            else
            {
                alice += (n - z) / 2;
                bob += (n - z) / 2;
                bob += z / 2;
                alice += z / 2;
            }
            if (alice > bob)
                cout << "ALICE" << nl;
            else if (alice < bob)
                cout << "BOB" << nl;
            else
                cout << "TIE" << nl;
        }
    }
    return 0;
}