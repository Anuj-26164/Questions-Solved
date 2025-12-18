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
        string s;
        cin >> s;

        stack<char> ch;
        bool possible = true;

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                ch.push(c);
            }
            else
            {
                if (ch.empty() || 
                   (c == ')' && ch.top() != '(') || 
                   (c == '}' && ch.top() != '{') || 
                   (c == ']' && ch.top() != '['))
                {
                    possible = false;
                    break;
                }
                ch.pop();
            }
        }

        if (!ch.empty())
            possible = false;

        cout << (possible ? "YES" : "NO") << '\n';
    }

    return 0;
}
