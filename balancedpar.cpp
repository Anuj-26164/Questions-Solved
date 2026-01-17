#include <bits/stdc++.h>
using namespace std;

void dfs(string s, int open, int close, int n, vector<string> &res)
{
    if (s.length() == 2 * n)
    {
        res.push_back(s);
        return;
    }

    if (open < n)
    {
        dfs(s + "(", open + 1, close, n, res);
    }

    if (close < open)
    {
        dfs(s + ")", open, close + 1, n, res);
    }
}

int main()
{
    int n = 5; // example input
    vector<string> res;

    dfs("", 0, 0, n, res);
    cout << res.size() << endl;
    for (string &p : res)
    {
        cout << p.size() << endl;
        cout << p << endl;
    }

    return 0;
}
