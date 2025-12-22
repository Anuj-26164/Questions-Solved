#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define lli long long int
#define forl for (int i = 0; i < n; i++)
#define nl '\n'

int main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        lli a, b, xk, yk, xq, yq, count = 0;
        cin >> a >> b;
        cin >> xk >> yk;
        cin >> xq >> yq;
        if (a != b)
        {
            lli arrk[8][2] = {
                {xk + a, yk + b},
                {xk + a, yk - b},
                {xk - a, yk + b},
                {xk - a, yk - b},
                {xk + b, yk + a},
                {xk + b, yk - a},
                {xk - b, yk + a},
                {xk - b, yk - a},
            };
            lli arrq[8][2] = {
                {xq + a, yq + b},
                {xq + a, yq - b},
                {xq - a, yq + b},
                {xq - a, yq - b},
                {xq + b, yq + a},
                {xq + b, yq - a},
                {xq - b, yq + a},
                {xq - b, yq - a},
            };
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (arrk[i][0] == arrq[j][0] && arrk[i][1] == arrq[j][1] )
                    {
                        count++;
                    }
                    
                }
            }
        }
        if (a == b)
        {
            lli arrk1[4][2] = {
                {xk + a, yk + a},
                {xk + a, yk - a},
                {xk - a, yk + a},
                {xk - a, yk - a},
            };
            lli arrq1[4][2] = {
                {xq + a, yq + b},
                {xq + a, yq - b},
                {xq - a, yq + b},
                {xq - a, yq - b},
            };
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (arrk1[i][0] == arrq1[j][0] && arrk1[i][1] == arrq1[j][1])
                    {
                        count++;
                    }
                }
            }
        }
        cout << count << nl;
    }
    return 0;
}