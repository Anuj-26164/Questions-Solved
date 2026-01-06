#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        vector<pair<int, char>> v;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] > 0)
                v.push_back({cnt[i], char('a' + i)});
        }

        sort(v.rbegin(), v.rend());

        // only one distinct character
        if (v.size() == 1)
        {
            cout << s << "\n";
            continue;
        }

        int x = v[0].first;
        int y = v[1].first;
        char mx = v[0].second;

        string ans;

        // place x - y copies first
        for (int i = 0; i < x - y; i++)
            ans.push_back(mx);

        v[0].first -= (x - y);

        // alternate remaining characters
        while (true)
        {
            bool placed = false;
            for (auto &p : v)
            {
                if (p.first > 0)
                {
                    ans.push_back(p.second);
                    p.first--;
                    placed = true;
                }
            }
            if (!placed)
                break;
        }

        cout << ans << "\n";
    }
    return 0;
}
