#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s, t;
    if (!(cin >> s >> t))
        return;

    vector<int> ns(26, 0), nt(26, 0);
    for (char c : s)
        ns[c - 'a']++;
    for (char c : t)
        nt[c - 'a']++;

    vector<int> ex(26, 0);
    for (int i = 0; i < 26; i++)
    {
        if (nt[i] < ns[i])
        {
            cout << "Impossible\n";
            return;
        }
        ex[i] = nt[i] - ns[i];
    }

    string res = "";
    for (char c : s)
    {
        int cur = c - 'a';
        for (int i = 0; i < cur; i++)
        {
            while (ex[i] > 0)
            {
                res += (char)('a' + i);
                ex[i]--;
            }
        }
        res += c;
    }

    for (int i = 0; i < 26; i++)
    {
        while (ex[i] > 0)
        {
            res += (char)('a' + i);
            ex[i]--;
        }
    }

    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}