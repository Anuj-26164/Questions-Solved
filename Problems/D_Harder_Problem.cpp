#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define lli long long int
#define nl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr(n + 1), sol(n + 1, 0);
        set<int> unused;

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            unused.insert(i);
        }

        for (int i = 1; i <= n; i++)
        {
            if (unused.count(arr[i])) 
            {
                sol[i] = arr[i];
                unused.erase(arr[i]); 
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (sol[i] == 0) 
            {
                sol[i] = *unused.begin();
                unused.erase(unused.begin());
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout << sol[i] << " ";
        }
        cout << nl;
    }
    return 0;
}
