// Qs: B_Petr_and_a_Combination_Lock
// CC: Anuj
// Time: 07:06:07

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
vector<int> generateAllSums(vector<int> &arr)
{
    int n = arr.size();
    int totalCombinations = 1 << n;
    std::vector<int> result;

    for (int mask = 0; mask < totalCombinations; ++mask)
    {
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                sum += arr[i];
            }
            else
            {
                sum -= arr[i];
            }
        }
        result.push_back(sum);
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bool possible = false;
    ninput();
    vector<int> arr(n);
    for (auto &c : arr)
        cin >> c;
    vector<int> allsum = generateAllSums(arr);
    for (int i = 0; i < allsum.size(); i++)
    {
        if (allsum[i] % 360 == 0)
        {
            possible = true;
            break;
        }
    }
    cout << (possible ? "YES" : "NO");

    return 0;
}
