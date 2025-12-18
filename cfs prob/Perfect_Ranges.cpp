// Qs: Perfect_Ranges
// Time: 22:42:11

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'
#define vin(v, n)               \
    vl v(n);                    \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> v[i];            \
    }

// bool isprime(int n) {
//     if (n <= 1) return false;
//     if (n <= 3) return true;
//     if (n % 2 == 0 || n % 3 == 0) return false;
//     for (int i = 5; i * i <= n; i += 6) {
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     }
//     return true;
long long nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r > n - r)
        r = n - r;
    long long res = 1;
    for (int i = 1; i <= r; i++)
    {
        res *= (n - r + i);
        res /= i;
    }
    return res;
}

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
    int N;
    cin >> N;
    vector<long long> A(N + 1), B(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    // Step 1: Normalize so A[i] < B[i]
    for (int i = 1; i <= N; i++)
    {
        if (A[i] > B[i])
            swap(A[i], B[i]);
    }

    vector<long long> dp0(N + 1, 0), dp1(N + 1, 0);

    // Base case
    dp0[1] = 1;
    dp1[1] = 1;
    long long ans = dp0[1] + dp1[1];

    // DP transitions
    for (int i = 2; i <= N; i++)
    {
        if (A[i] > B[i - 1])
        {
            // Case 1
            dp0[i] = dp0[i - 1] + dp1[i - 1] + 1;
            dp1[i] = dp0[i - 1] + dp1[i - 1] + 1;
        }
        else if (B[i - 1] > A[i] && A[i] > A[i - 1])
        {
            // Case 2
            dp0[i] = dp0[i - 1] + 1;
            dp1[i] = 1 + dp0[i - 1] + (B[i] > B[i - 1] ? dp1[i - 1] : 0);
        }
        else
        {
            // Case 3
            dp0[i] = 1;
            dp1[i] = 1 + (B[i] > A[i - 1] ? dp0[i - 1] : 0) + (B[i] > B[i - 1] ? dp1[i - 1] : 0);
        }
        ans += dp0[i] + dp1[i];
    }

    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}