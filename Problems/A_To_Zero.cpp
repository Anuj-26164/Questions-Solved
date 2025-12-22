// Qs: A_To_Zero
// Time: 15:54:29

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'
#define vin(v, n)               \
    vl v(n);                    \
    for (int i = 0; i < n; i++) \
        cin >> v[i];

void yes()
{
    cout << "YES" << endl;
}

void no()
{
    cout << "NO" << endl;
}

#define msb(mask) (63 - __builtin_clzll(mask)) /// 0 -> -1
#define lsb(mask) __builtin_ctzll(mask)        /// 0 -> 64
#define cntsetbit(mask) __builtin_popcountll(mask)
#define checkbit(mask, bit) ((mask >> bit) & 1ll)
#define onbit(mask, bit) ((mask) | (1LL << (bit)))
#define offbit(mask, bit) ((mask) & ~(1LL << (bit)))
#define changebit(mask, bit) ((mask) ^ (1LL << bit))

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll x, k;
        cin >> x >> k;
        if (x % 2 == 0 && k % 2 == 0)
        {
            cout << (x % k == 0 ? x / k : x / k + 1);
        }
        if (x % 2 != 0 && k % 2 != 0)
        {
            x -= k;
            k--;
            cout << (x % k == 0 ? x / k + 1 : x / k + 2);
        }
        if (x % 2 == 0 && k % 2 != 0)
        {
            k--;
            cout << (x % k == 0 ? x / k : x / k + 1);
        }
        if (x % 2 != 0 && k % 2 == 0)
        {
            k--;
            cout << (x % k == 0 ? x / k : x / k + 1);
        }
        cout<<nl;
    }
    return 0;
}