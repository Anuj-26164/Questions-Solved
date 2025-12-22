// Qs: A_Was_there_an_Array
// Time: 19:58:52

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
        ll n;
        cin >> n;
        bool possible = true;
        vin(arr, n - 2);
        if (n == 3 || n == 4)
        {
            possible = true;
        }
        else
        {
            f(0, n - 4)
            {
                if (arr[i] == 1 && arr[i + 1] == 0 && arr[i + 2] == 1)
                {
                    possible = false;
                    break;
                }
            }
        }
        if (possible)
            yes();
        else
            no();
    }
    return 0;
}