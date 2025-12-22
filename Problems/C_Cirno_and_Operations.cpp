// Qs: C_Cirno_and_Operations
// CC: Anuj
// Time: 21:11:14

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define forl for (int i = 0; i < n; i++)
#define input(x, y) \
    int x, y;       \
    cin >> x;       \
    cin >> y;
#define ninput() \
    int n;       \
    cin >> n;
#define arrinput()      \
    vl arr(n);          \
    for (auto &c : arr) \
        cin >> c;
#define forl for (int i = 0; i < n; i++)
#define nl '\n'

// bool isEven(int n)
// {
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
//    return sum;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bool possible = false;
    int t;
    cin >> t;
    while (t--)
    {
        ninput();
        vl vec(n);
        for (auto &c : vec)
            cin >> c;
        ll sum = accumulate(vec.begin(), vec.end(), 0ll);
        while (1)
        {
            if (vec.size() == 1)
            {
                sum = max(sum, (vec[0]));
                break;
            }
            vl sol;
            for (ll i = 0; i < vec.size() - 1; i++)
            {
                sol.push_back(vec[i + 1] - vec[i]);
            }
            if (accumulate(sol.begin(), sol.end(), 0LL) < 0)
            {
                for (auto &c : sol)
                {
                    c = -c;
                }
            }
            sum = max(sum, accumulate(sol.begin(), sol.end(), 0LL));
            reverse(sol.begin(), sol.end());
            vec = sol;
        }
        cout << sum << nl;
    }
    return 0;
}