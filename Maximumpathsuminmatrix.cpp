#include <bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m, 0), curr(m, 0);

    for (int j = 0; j < m; j++)
    {
        prev[j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = prev[j];
            int leftDiag = (j > 0) ? prev[j - 1] : INT_MIN;
            int rightDiag = (j < m - 1) ? prev[j + 1] : INT_MIN;

            curr[j] = max({up, leftDiag, rightDiag}) + matrix[i][j];
        }
        prev = curr;
    }

    return *max_element(prev.begin(), prev.end());
}
