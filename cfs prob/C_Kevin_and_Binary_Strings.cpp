// Qs: C_Kevin_and_Binary_Strings
// Time: 02:33:31

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
        string s;
        cin >> s;
        ll n = s.size();
        ll first0 = -1;
        for (int i = 0; i<n; i++)
        {
            if (s[i] == '0')
            {
                first0 = i;
                break;
            }
        }
        ll q = 0;
        for (int i = first0; i<n; i++)
        {
            if (s[i] == '0')
                q++;
            else
                break;
        }
        ll z = min(first0, q);
        if (first0 != -1)
        {
            cout << 1 << " " << n << " " << first0 - z + 1 << " " << n - z << nl;
            // cout<<first0<<" "<<q<<" "<<z<<nl;
        }
        else
        {
            cout << 1 << " " << n << " " << n << " " << n << nl;
        }
    }
    return 0;
}