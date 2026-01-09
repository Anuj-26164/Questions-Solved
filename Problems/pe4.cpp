#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(int n)
{
    string s = to_string(n);
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}
int main()
{
    int ans = 0;
    for (int i = 100; i <= 999; i++)
    {
        for (int j = 100; j <= 999; j++)
        {
            int prod = i * j;
            if (ispalindrome(prod))
                ans = max(ans, prod);
        }
    }
    cout << ans << "\n";
    return 0;
}