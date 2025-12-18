#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define lli long long int
#define forl for (int i = 0; i < n; i++)
#define nl '\n'

int isSorted(const vector<int> &arr)
{
    for (size_t i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, count = 0;
        cin >> n;
        vi arr(n);
        forl
        {
            cin >> arr[i];
        }
        if (isSorted(arr))
        {
            cout << n << nl;
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << nl;
        }
        else
        {
            for (int i = 0; i < n - 1; i++) // Ensure i+1 is within bounds
            {
                if (arr[i] > arr[i + 1])
                {
                    count += 2;
                }
                else
                {
                    count += 1;
                }
            }
            cout << count+1 << nl;
            for (int i = 0; i < n - 1; i++) // Ensure i+1 is within bounds
            {
                if (arr[i] > arr[i + 1])
                {
                    cout << arr[i] << " " << arr[i + 1] << " ";
                }
                else
                {
                    cout << arr[i] << " ";
                }
            }
            cout << arr[n - 1] << nl; // Handle last element separately
        }
    }
    return 0;
}
