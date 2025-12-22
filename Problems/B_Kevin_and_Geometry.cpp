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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        map<int, int> frequencyMap;

        for (auto &i : arr)
            cin >> i, frequencyMap[i] += 1;

        int pairCount = 0;
        vector<int> oddElements;
        vector<int> evenElements;
        int firstOdd, secondOdd;
        int minDifference = 1e9;

        for (auto [element, count] : frequencyMap)
        {
            if (count >= 2)
            {
                pairCount += count / 2;
                evenElements.push_back(element);
                if (count % 2 == 1)
                    oddElements.push_back(element);
            }
            else
            {
                oddElements.push_back(element);
            }
        }

        for (int i = 1; i < oddElements.size(); i++)
        {
            if (oddElements[i] - oddElements[i - 1] < minDifference)
            {
                minDifference = oddElements[i] - oddElements[i - 1];
                firstOdd = oddElements[i];
                secondOdd = oddElements[i - 1];
            }
        }

        if (pairCount == 0)
        {
            cout << -1 << nl;
        }
        else if (pairCount == 1)
        {
            int singleElement = evenElements[0];
            if (singleElement * 2 > minDifference)
            {
                cout << firstOdd << " " << singleElement << " " << secondOdd << " " << singleElement << nl;
            }
            else
                cout << -1 << nl;
        }
        else
        {
            if (evenElements.size() == 1)
            {
                cout << evenElements[0] << " " << evenElements[0] << " " << evenElements[0] << " " << evenElements[0] << nl;
            }
            else
            {
                cout << evenElements[0] << " " << evenElements[0] << " " << evenElements[1] << " " << evenElements[1] << nl;
            }
        }
    }

    return 0;
}
