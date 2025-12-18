#include <bits/stdc++.h>
using namespace std;
#define vl vector<long long>
#define pb push_back
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'
#define msb(mask) (63 - __builtin_clzll(mask))       // position of msb
#define lsb(mask) __builtin_ctzll(mask)              // position of lsb
#define cntsetbit(mask) __builtin_popcountll(mask)   // number of set bits
#define checkbit(mask, bit) ((mask >> bit) & 1ll)    // check if bit is set
#define onbit(mask, bit) ((mask) | (1LL << (bit)))   // sets the bit-th bit of mask to 1
#define offbit(mask, bit) ((mask) & ~(1LL << (bit))) // sets the bit-th bit of mask to 0
#define changebit(mask, bit) ((mask) ^ (1LL << bit)) // flips the bit-th bit of mask

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    vl arr(n);
    ll min_msb = LLONG_MAX;
    ll min_sb = LLONG_MAX;
    ll alpha = -1;
    ll beta = -1;
    ll idx,idx1;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ll curr_msb = msb(arr[i]);
        if (curr_msb < min_msb) 
        {
            min_msb = curr_msb;
            alpha = arr[i];
            idx = i;
        }
        ll curr_sb = cntsetbit(arr[i]);
        if (curr_sb < min_sb) 
        {
            min_sb = curr_sb;
            beta = arr[i];
            idx = i;
        }
    }

    if (alpha != -1) 
    {
        alpha = (alpha) ^ (32767);
        arr[idx] = alpha;
    }

    ll x = 0;
    for (int i = 0; i < n; i++)
    {
        x = (x | arr[i]);
    }

    cout << x << nl;

    return 0;
}
