// Qs: B_Perfecto
// Time: 20:33:36

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
bool isPerfectSquare(long long x)
{
    if (x < 0)
        return false;
    long long s = sqrt(x);
    return s * s == x;
}

bool isSumPerfectSquare(long long n)
{
    long long sum = n * (n + 1) / 2;
    return isPerfectSquare(sum);
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
        vl unused;
        if (isSumPerfectSquare(n))
        {
            cout << -1 << nl;
            continue;
        }
        else
        {
            ll sum = 0;
            for (int i = n; i >= 1; i--)
            {
                if (!isPerfectSquare(sum + i))
                {
                    cout << i << " ";
                    sum += i;
                }
                else
                {
                    unused.pb(i);
                }
            }
        }
        if (unused.size() != 0)
        {
            sort(unused.begin(), unused.end(), greater<int>());
            for (auto &c : unused)
            {
                cout << c << " ";
            }
        }
        cout << nl;
    }
    return 0;
}