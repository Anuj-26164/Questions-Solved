#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++)
    {
        int j = i - 1, cur = i;
        while (j >= 0 && s[cur] > '0' && s[cur] > s[j] + 1)
        {
            s[cur]--;
            swap(s[cur], s[j]);
            cur--;
            j = cur - 1;
        }
    }
    cout << s;
    cout << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}