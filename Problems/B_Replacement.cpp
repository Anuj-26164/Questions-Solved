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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, count1s = 0, count1x = 0;
        cin >> n;
        string s, x;
        bool replace = true;
        cin >> s >> x;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                count1s++;
        }
        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] == '1')
                count1x++;
        }
        int count0s = s.size() - count1s;
        int count0x = x.size() - count1x;
        if (count1s == s.size() || count0s == s.size())
        {
            cout << "NO" << nl;
        }
        else
        {
            for (int i = 0; i < x.size(); i++)
            {
                if (x[i] == '1')
                {
                    count0s--;
                }
                if (x[i] == '0')
                {
                    count1s--;
                }
                if ((count0s == 0 || count1s == 0) && i != x.size() - 1)
                {
                    replace = false;
                }
            }
            cout << (replace ? "YES" : "NO") << nl;
        }
    }
    return 0;
}