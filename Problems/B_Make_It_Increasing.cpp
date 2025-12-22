#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define nl '\n'
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, count = 0;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        for (int i = n - 1; i >= 1; --i)
        {
            while (arr[i - 1] >= arr[i])
            {
                (arr[i - 1]) >>= 1;
                count++;
                if (arr[i - 1] == 0 && i != 1)
                {
                    count = -1;
                    break;
                }
            }
            if (count == -1)
                break;
        }

        cout << count << nl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}
