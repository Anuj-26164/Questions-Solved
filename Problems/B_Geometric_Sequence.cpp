#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> gp(n);
    for (auto &c : gp)
        cin >> c;
    if (n == 2)
    {
        if (gp[0] != 0 || gp[1] != 0)
        {
            cout << "No";
            return 0;
        }
        else
        {
            cout << "Yes";
        }
    }
    else
    {
        bool possible = true;
        for (int i = 1; i < n - 1; i++)
        {
            if (gp[i] * gp[i] != gp[i - 1] * gp[i + 1])
            {
                possible = false;
                break;
            }
        }
        cout << (possible ? "Yes" : "No");
        return 0;
    }
}
