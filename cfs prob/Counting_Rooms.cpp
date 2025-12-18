#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    vector<vector<int>> visited(n, vector<int>(m, 0));
    int di[4] = {0, 1, -1, 0};
    int dj[4] = {1, 0, 0, -1};

    int rooms = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                rooms++;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = 1;

                while (!q.empty())
                {
                    auto [r, c] = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int ni = r + di[k], nj = c + dj[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                            grid[ni][nj] == '.' && !visited[ni][nj])
                        {
                            visited[ni][nj] = 1;
                            q.push({ni, nj});
                        }
                    }
                }
            }
        }
    }
    cout << rooms << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
