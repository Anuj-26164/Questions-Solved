// Qs: B_Black_Cells
// Time: 17:32:11

#include <bits/stdc++.h>
using namespace std;

#define read(x) scanf("%lld", &x)
#define read2(x, y) scanf("%lld %lld", &x, &y)
#define read3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define print(x) printf("%lld\n", x)
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

// bool isprime(int n) {
//     if (n <= 1) return false;
//     if (n <= 3) return true;
//     if (n % 2 == 0 || n % 3 == 0) return false;
//     for (int i = 5; i * i <= n; i += 6) {
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     }
//     return true;

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

bool pred(ll x, vl &arr)
{
    bool flag = true;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i + 1] - arr[i] <= x)
            continue;
        else
        {
            flag = false;
            break;
        }
    }
    return flag ? 1 : 0;
}
void insertModified(vector<ll> &v) {
    int n = v.size();
    int maxDiff = 0, idx = -1;

    for (int i = 0; i < n - 1; i++) {
        int diff = v[i + 1] - v[i];
        if (diff > maxDiff) {
            maxDiff = diff;
            idx = i;
        }
    }

    int newVal = v[idx + 1] - 1;
    v.insert(v.begin() + idx + 1, newVal);
}
int main()
{
    ll t;
    read(t);
    while (t--)
    {
        ll n;
        read(n);
        vin(arr, n);
        if(n!=1)
        {if(n%2)
        {
            insertModified(arr);
        }
        ll maxdiff=0;
        for(int i=0;i<n-1;i+=2)
        {
            maxdiff=max(maxdiff,arr[i+1]-arr[i]);
        }
        print(maxdiff);}
        else 
        {
            print(1);
        }
    }
    return 0;
}