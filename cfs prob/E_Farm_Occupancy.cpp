#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nkinput() \
    int n, k;     \
    cin >> n;     \
    cin >> k;
#define ninput() \
    int n;       \
    cin >> n;
#define arrinput()      \
    vl arr(n);          \
    for (auto &c : arr) \
        cin >> c;
#define forl for (int i = 0; i < n; i++)
#define nl '\n'
// bool isEven(int n) {
//     return (n & 1) == 0;
// }

// bool isSorted(const vi& vec) {
//     for (size_t i = 0; i < vec.size() - 1; ++i) {
//         if (vec[i] > vec[i + 1]) {
//             return false;
//         }
//     }
//     return true;
// }

// long long bin_exp(long long base, long long exp, long long mod) {
//     long long result = 1;
//     while (exp > 0) {
//         if (exp & 1) result = (result * base) % mod;
//         base = (base * base) % mod;
//         exp >>= 1;
//     }
//     return result;
// }

// bool isprime(int n) {
//     if (n <= 1) return false;
//     if (n <= 3) return true;
//     if (n % 2 == 0 || n % 3 == 0) return false;
//     for (int i = 5; i * i <= n; i += 6) {
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     }
//     return true;
// }

// int power(int N, int M) {
//     int power = N, sum = 1;
//     if (N == 0) sum = 0;
//     while (M > 0) {
//         if ((M & 1) == 1) {
//             sum *= power;
//         }
//         power = power * power;
//         M = M >> 1;
//     }
//     return sum;
// }

// ll numofdiv(ll c) {
//     ll count = 0;
//     for (ll i = 1; i * i <= c; i++) {
//         if (c % i == 0) {
//             count++;
//             if (i != c / i) count++;
//         }
//     }
//     return count;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll L, H;
        cin >> L >> H;

        ll n, m;
        cin >> n >> m;

        vl a(n), b(m);
        for (ll &x : a)
            cin >> x;
        for (ll &y : b)
            cin >> y;

        ll c;
        cin >> c;

        vl p(c), q(c);
        for (ll &x : p)
            cin >> x;
        for (ll &y : q)
            cin >> y;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        map<pair<ll, ll>, ll> region_count;

        for (ll i = 0; i < c; i++)
        {
            ll x_idx = lower_bound(a.begin(), a.end(), p[i]) - a.begin();
            ll y_idx = lower_bound(b.begin(), b.end(), q[i]) - b.begin();
            region_count[{x_idx, y_idx}]++;
        }

        ll min_cows = LLONG_MAX, max_cows = 0;

        for (auto &[_, count] : region_count)
        {
            min_cows = min(min_cows, count);
            max_cows = max(max_cows, count);
        }

        if (region_count.size() < (n + 1) * (m + 1))
        {
            min_cows = 0;
        }

        cout << min_cows << nl << max_cows << nl;
    }
    return 0;
}

