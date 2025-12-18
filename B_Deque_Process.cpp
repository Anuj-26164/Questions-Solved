// Qs: B_Deque_Process
// Time: 20:54:58

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

bool hasConsecutive5(const vector<long long> &v)
{
    int inc = 1, dec = 1;
    for (size_t i = 1; i < v.size(); ++i)
    {
        if (v[i] == v[i - 1] + 1)
        {
            inc++;
            dec = 1;
        }
        else if (v[i] == v[i - 1] - 1)
        {
            dec++;
            inc = 1;
        }
        else
        {
            inc = dec = 1;
        }

        if (inc == 5 || dec == 5)
            return true;
    }
    return false;
}

void solve()
{
    ll n;
    cin >> n;
    vin(v, n);
    string s = "";
    ll l = 0, r = n - 1;
    ll cnt = 0;
    vl z;
    while (l <= r)
    {
        if (cnt % 2 == 0)
        {
            if (v[l] < v[r])
            {
                s += 'L';
                l++;
                // z.push_back(v[l]);
            }
            else
            {
                s += 'R';
                r--;
                // z.push_back(v[r]);
            }
        }
        else
        {
            if (v[l] < v[r])
            {
                s += 'R';
                r--;
                // z.push_back(v[r]);
            }
            else
            {
                s += 'L';
                l++;
                // z.push_back(v[l]);
            }
        }
        cnt++;
    }
    // cout << hasConsecutive5(z);
    cout << s << nl;
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