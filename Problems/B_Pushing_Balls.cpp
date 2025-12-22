// Qs: B_Pushing_Balls
// Time: 11:54:05

#include <bits/stdc++.h>
using namespace std;

#define read(x) scanf("%lld", &x)
#define read2(x, y) scanf("%lld %lld", &x, &y)
#define read3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define print(x) printf("%lld\n", x)
#define vl vector<long long>
#define all(x) begin(x), end(x)
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

int main()
{
    ll t;
    read(t);
    while (t--)
    {
        ll n, m;
        read2(n, m);
        vector<string> v(n);
        for (auto &c : v)
            cin >> c;
        bool flag=true;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m && flag==true; j++)
            {
                if(v[i][j]=='0') continue;
                else
                {
                    for(int k=0;k<j;k++)
                    {
                        if(v[i][k]=='0')
                        {
                            flag=false;
                            break;
                        }
                    }
                    int lambda=1;
                    for(int k=0;k<i && flag==false;k++)
                    {
                        lambda&=(v[k][j]-'0');
                    }
                    if(lambda==1) flag=true;
                }
            }
        }
        if(flag) yes();
        else no();
    }
    return 0;
}