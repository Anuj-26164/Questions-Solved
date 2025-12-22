#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = S.size();

    vector<int> tpos;
    for (int i = 0; i < n; ++i)
    {
        if (S[i] == 't')
            tpos.push_back(i);
    }

    long double maxRate = 0.0L;

    for (int i = 0; i < (int)tpos.size(); ++i)
    {
        for (int j = i + 1; j < (int)tpos.size(); ++j)
        {
            int length = tpos[j] - tpos[i] + 1;
            int tCount = j - i + 1;
            if (length >= 3 && tCount >= 3)
            {
                long double rate = (tCount - 2)/(long double)(length - 2) ;
                maxRate = max(maxRate, rate);
            }
        }
    }

    cout << fixed << setprecision(20) << maxRate << "\n";
}
