// Qs: C_Rotatable_Array
// Time: 00:36:09

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

void reverse(vector<int> &nums, int l, int r)
{
    while (r > l)
    {
        swap(nums[r], nums[l]);
        r--, l++;
    }
}

void operation1(vector<int> &nums, int p, int x)
{
    nums[p - 1] = x;
}
void operation2(vector<int> &nums, int p)
{
    cout << nums[p - 1] << nl;
}
void operation3(vector<int> &nums, int k)
{
    k %= nums.size();
    k = nums.size() - k;
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    int offset = 0; // logical left rotation offset

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int p, x;
            cin >> p >> x;
            p--; // make 0-indexed
            int idx = (p + offset) % n;
            arr[idx] = x;
        }
        else if (type == 2)
        {
            int p;
            cin >> p;
            p--; // make 0-indexed
            int idx = (p + offset) % n;
            cout << arr[idx] << nl;
        }
        else if (type == 3)
        {
            int k;
            cin >> k;
            offset = (offset + k) % n; // left rotation increases logical offset
        }
    }
}

int main()
{
    {
        solve();
    }
    return 0;
}