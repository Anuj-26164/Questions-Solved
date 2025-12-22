#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
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

vector <string> perm;
bool arrange(int x, int y)
{
    if (x < y)
        return perm[x][y] == '1';
    else
        return perm[x][y] == '0';
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

        int n;
        cin >> n;
        perm.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> perm[i];
        }
        vi perm1(n);
        for (int i = 0; i < n; i++)
        {
            perm1[i] = i;
        }
        sort(perm1.begin(), perm1.end(), arrange);
        for (int i = 0; i < n; i++)
        {
            cout << perm1[i] + 1;
            if (i + 1 != n)
                cout << " ";
        }
        cout << nl;
    }
    return 0;
}