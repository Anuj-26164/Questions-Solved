// Qs: C_Choose_the_Different_Ones
// CC: Anuj
// Time: 23:59:15

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

bool isEven(int n)
{
    return (n & 1) == 0;
}

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
        int n, m, k;
        cin >> n >> m >> k;
        vl arr1(n), arr2(m);
        for (auto &c : arr1)
            cin >> c;
        for (auto &c : arr2)
            cin >> c;
        vl arr3(k + 1), arr4(k + 1);
        for (auto &c : arr1)
        {
            if (c <= k)
            {
                arr3[c] = 1;
            }
        }
        for (auto &c : arr2)
        {
            if (c <= k)
            {
                arr4[c] = -1;
            }
        }
        int count1 = 0, count2 = 0, countcommon = 0;
        for (int i = 1; i <= k; i++)
        {
            if (arr3[i] == 0 && arr4[i] == -1)
                count2++;
            if (arr3[i] == 1 && arr4[i] == 0)
                count1++;
            if (arr3[i] == 1 && arr4[i] == -1)
                countcommon++;
            if (arr3[i] == 0 && arr4[i] == 0)
            {
                cout << "NO" << nl;
                goto nextcase;
            }
        }
        if (count1 <= k / 2 && count2 <= k / 2)
        {
            if (count1 + count2 + countcommon == k)
            {
                cout << "YES" << nl;
            }
        }
        else
            cout << "NO" << nl;
    nextcase:
    }
    return 0;
}