#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k, m;
        cin >> n >> k >> m;

        string s;
        cin >> s;

        string res = "";             // counter-case string
        vector<bool> seen(k, false); // tracks characters in current segment
        int distinct = 0;

        // Traverse the string
        for (char c : s)
        {
            if ((int)res.size() == n)
                break;

            int idx = c - 'a';

            // First time seeing this character in this segment
            if (!seen[idx])
            {
                seen[idx] = true;
                distinct++;
            }

            // All k characters seen → must take one character
            if (distinct == k)
            {
                res.push_back(c); // forced choice
                fill(seen.begin(), seen.end(), false);
                distinct = 0;
            }
        }

        // If we managed to build length n → all strings exist
        if ((int)res.size() == n)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";

            // Find a character not present in the remaining suffix
            for (int i = 0; i < k; i++)
            {
                if (!seen[i])
                {
                    while ((int)res.size() < n)
                        res.push_back('a' + i);
                    break;
                }
            }

            cout << res << "\n";
        }
    }

    return 0;
}
