#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> bk(N + 1, 0);
    for (int i = 0; i < Q; i++)
    {
        if (i)
        {
            cout << " ";
        }

        int X;
        cin >> X;
        if (X >= 1)
        {
            bk[X]++;
            cout << X;
        }
        else
        {
            int y = 1;
            for (int j = 2; j <= N; j++)
            {
                if (bk[y] > bk[j])
                {
                    y = j;
                }
            }
            bk[y]++;
            cout << y;
        }
    }
    cout << "\n";
    return 0;
}
