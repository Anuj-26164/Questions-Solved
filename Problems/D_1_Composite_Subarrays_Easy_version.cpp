// Qs: D_1_Composite_Subarrays_Easy_version
// CC: Anuj
// Time: 21:36:57

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define forl for (int i = 0; i < n; i++)
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

bool isprime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

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
ll n, k;
    cin >> n >> k;
    vl arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll count = 0;
    ll prime_count = 0;
    int i = 0;

    for (int j = 0; j < n; j++)
    {
        if (isprime(arr[j]))
        {
            prime_count++;
        }
        while (prime_count > k)
        {
            if (isprime(arr[i]))
            {
                prime_count--;
            }
            i++;
        }
        count += (j - i + 1);
    }

    cout << count;
    return 0;
}