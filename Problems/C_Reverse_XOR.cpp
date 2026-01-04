#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        long long x;
        cin >> x;

        string n = bitset<64>(x).to_string();
        auto pos = n.find_first_not_of('0');
        if (pos == string::npos)
            n = "0";
        else
            n.erase(0, pos);

        string ans = "NO";

        for (int i = n.size(); i <= 64; i++)
        {
            if ((int)n.size() <= i)
            {
                string w(i - n.size(), '0');
                w += n;

                string rev = w;
                reverse(rev.begin(), rev.end());
                bool B = (w == rev);

                if (i % 2 == 1)
                {
                    B = B && (w[i / 2] == '0');
                }

                if (B)
                {
                    ans = "YES";
                    break;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
