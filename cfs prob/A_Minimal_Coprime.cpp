#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
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

// bool isprime(int n) {
//     if (n <= 1) return false; // 0 and 1 are not prime
//     if (n <= 3) return true;  // 2 and 3 are prime
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

// vector<ll> computePrefixSum(const vector<ll>& arr) {
//     ll n = arr.size();
//     vector<ll> prefixSum(n);
//     prefixSum[0] = arr[0];
//     for (int i = 1; i < n; ++i) {
//         prefixSum[i] = prefixSum[i - 1] + arr[i];
//     }
//     return prefixSum;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        l = l - 1;
        r = r - 1;
        vl sol(r - l + 1);
        vl vec(n - (r - l + 1));
        vl arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i >= l && i <= r)
            {
                sol.pb(arr[i]);
            }
            else
                vec.pb(arr[i]);
        }
        sort(sol.begin(), sol.end(), greater<int>());
        sort(vec.begin(), vec.end());
        int k = 0;
        for (int i = 0; i < sol.size(); i++)
        {
            if (vec[i] >= sol[i])
            {
                k = i;
                break;
            }
        }
        cout << accumulate(vec.begin(), vec.begin() + k, 0) + accumulate(sol.begin() + k + 1, sol.end(), 0) << nl;
    }
    return 0;
}