#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k, m, count = 0;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i == k - 1)
        {
            m = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= m && arr[i] > 0)
        {
            count++;
        }
    }
    cout << count << endl;
}
int main()
{
    solve();
    return 0;
}