#include <bits/stdc++.h>
using namespace std;

#define forl for (int i = 0; i < n; i++)
#define nl '\n'

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

        int arr[2][n];
        forl cin >> arr[0][i];
        forl cin >> arr[1][i];

        int maxi = arr[0][0] + arr[1][0];
        int k = 0, maxsum = 0;

        for (int i = 1; i < n; i++) 
        {
            if (arr[0][i] + arr[1][i] > maxi)
            {
                maxi = arr[0][i] + arr[1][i];
                k = i;
            }
        }

        forl 
        {
            if (i != k)
            {
                maxsum += max(arr[0][i], arr[1][i]);
            }
        }

        cout << maxsum + maxi << nl;
    }

    return 0;
}
