// Qs: Palindrome_Reorder
// Time: 12:03:22

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
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

// long long bin_exp(long long base, long long exp, long long mod) {
//     long long result = 1;
//     while (exp > 0) {
//         if (exp & 1) result = (result * base) % mod;
//         base = (base * base) % mod;
//         exp >>= 1;
//     }
//     return result;
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
//     return sum;
// }

// void binsearch(vl &arr,ll x) {
//    int lo = 0, hi = arr.size() - 1;
//    int mid;
//    while (hi - lo > 1)
//    {
//        mid = (hi + lo)>>1;
//        if (arr[mid] < x)
//        {
//            lo = mid + 1;
//        }
//        else
//            hi = mid;
//    }
//    if (arr[lo] == x)
//    {
//        cout << lo << nl;
//    }
//    else if (arr[hi] == x)
//        cout << hi << nl;
//    else
//        cout << -1 << nl;
//}

void yes()
{
    cout << "YES" << endl;
}

void no()
{
    cout << "NO" << endl;
}

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
    cout.tie(nullptr);
    string s;
    cin >> s;
    vl hash(26);
    f(0, s.size())
    {
        hash[s[i] - 'A']++;
    }
    if (s.size() % 2 == 0)
    {
        f(0, 26)
        {
            if (hash[i] % 2 != 0)
            {
                cout << "NO SOLUTION";
                return 0;
            }
        }
        string str;
        for (int j = 0; j < hash.size(); j++)
        {

            for (int i = 0; i < hash[j] / 2; i++)
            {
                str += j + 'A';
            }
        }
        string rev_str = str;
        reverse(rev_str.begin(), rev_str.end());
        cout << str + rev_str;
    }
    else
    {
        int countodd = 1;
        f(0, 26)
        {
            if (hash[i] % 2 != 0)
            {
                countodd--;
                if (countodd < 0)
                {
                    cout << "NO SOLUTION";
                    return 0;
                }
            }
        }
        string str;
        string middle;
        for (int j = 0; j < hash.size(); j++)
        {

            if (hash[j] % 2 != 0)
            {
                middle = j + 'A';
                hash[j]--;
            }
        }
        for (int j = 0; j < hash.size(); j++)
        {

            for (int i = 0; i < hash[j] / 2; i++)
            {
                str += j + 'A';
            }
        }
        string rev_str = str;
        reverse(rev_str.begin(), rev_str.end());
        cout << str + middle + rev_str;
    }
    return 0;
}