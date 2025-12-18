#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    // Step 1: take first element from each row
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        xr ^= a[i][0];
    }

    vector<int> ans(n, 0);

    // Step 2: if XOR already non-zero
    if (xr != 0)
    {
        cout << "TAK\n";
        for (int i = 0; i < n; i++)
            cout << 1 << " ";
        cout << "\n";
        return 0;
    }

    // Step 3: try to fix XOR using one flexible row
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (a[i][j] != a[i][0])
            {
                // Change only this row
                cout << "TAK\n";
                for (int k = 0; k < n; k++)
                {
                    if (k == i)
                        cout << j + 1 << " ";
                    else
                        cout << 1 << " ";
                }
                cout << "\n";
                return 0;
            }
        }
    }

    // Step 4: no solution
    cout << "NIE\n";
    return 0;
}
