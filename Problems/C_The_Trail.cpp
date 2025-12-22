#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
            }
        }

        vector<pair<int, int>> path;
        int r = 0, c = 0;
        path.push_back({r, c});

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'D')
            {
                ++r;
            }
            else
            {
                ++c;
            }
            path.push_back({r, c});
        }

        for (size_t k = 0; k < path.size(); ++k)
        {
            r = path[k].first;
            c = path[k].second;

            if (k < path.size() - 1)
            {
                int next_r = path[k + 1].first;
                int next_c = path[k + 1].second;
                if (next_r > r)
                {
                    int row_sum = 0;
                    for (int j = 0; j < m; ++j)
                    {
                        row_sum += a[r][j];
                    }
                    a[r][c] = -(row_sum - a[r][c]);
                }
            }
                else
                {
                    int col_sum = 0;
                    for (int i = 0; i < n; ++i)
                    {
                        col_sum += a[i][c];
                    }
                    a[r][c] = -(col_sum - a[r][c]);
                }
            }

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    cout << a[i][j] << " ";
                }
                cout << "\n";
            }
        }
        return 0;
    }
