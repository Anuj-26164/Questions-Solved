    // Qs: G_Sum_of_Two_Values
    // Time: 17:36:16
     
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
            read(v[i]);
     
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
     
    void solve()
    {
        ll n, x;
        cin>>n>>x;
        vin(a, n);
        vl v = a;
        sort(all(v));
        ll l = 0, r = n - 1;
        while (r > l)
        {
            if (v[r] + v[l] > x)
                r--;
            else if (v[r] + v[l] < x)
                l++;
            else
                break;
        }
        if (v[r] + v[l] != x || r == l)
            cout<<"IMPOSSIBLE"<<nl;
        else
        {
            int idx1,idx2=-1;
            f(0,n)
            {
                if(a[i]==v[r])
                {
                    idx1=i+1;
                    break;
                }
            }
            f(0,n)
            {
                if(a[i]==v[l] && i+1!=idx1)
                {
                    idx2=i+1;
                    break;
                }
            }
            if(idx2==-1) cout<<"IMPOSSIBLE"<<nl;
            else cout<<idx1<<" "<<idx2<<nl;
        }
    }
    int main()
    {
        {
            solve();
        }
        return 0;
    }