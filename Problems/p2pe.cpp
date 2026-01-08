#include <bits/stdc++.h>
using namespace std;

int main()
{
    int dp1 = 1, dp2 = 2, ans = 0;
    while (dp2 <= 4000000)
    {
        if (dp2 % 2 == 0)
            ans += dp2;
        int x = dp2;
        dp2 = dp2 + dp1;
        dp1 = x;
    }
    cout << ans;
    return 0;
}