#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
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
bool checkRowsForGivenDifference(const std::vector<std::vector<int>> &matrix, int expectedDiff)
{
    for (const auto &row : matrix)
    {
        if (row.size() < 2)
            continue;

        for (size_t i = 1; i < row.size(); ++i)
        {
            if (row[i] - row[i - 1] != expectedDiff)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> cows(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> cows[i][j];
            }
        }
        if(m!=1)
        {for (auto &row : cows)
        {
            sort(row.begin(), row.end());
        }
        if (!checkRowsForGivenDifference(cows, n))
        {
            cout << -1;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << cows[i][0] + 1 << " ";
            }
        }
        cout << nl;}
        else
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==cows[j][0])
                    cout<<j+1<<" ";
                }
            }

            cout<<nl;
        }
    }
    return 0;
}