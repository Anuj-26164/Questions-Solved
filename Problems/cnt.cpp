#include <bits/stdc++.h>
using namespace std;

long long dp[20][2][2]; // idx, tight, hasZero
string s;

long long solve(int idx, int tight, int hasZero)
{
    if (idx == s.size())
        return hasZero;
    long long &res = dp[idx][tight][hasZero];
    if (res != -1)
        return res;

    int ub = (tight ? s[idx] - '0' : 9);
    long long ans = 0;

    for (int dig = 0; dig <= ub; dig++)
    {
        ans += solve(idx + 1, tight && (dig == ub), hasZero || (dig == 0 && idx != 0));
    }
    return res = ans;
}

long long countNumbersWithZero(long long n)
{
    s = to_string(n);
    memset(dp, -1, sizeof dp);
    return solve(0, 1, 0);
}

long long countNoZeroNumbers(long long n)
{
    return n - countNumbersWithZero(n);
}

int main()
{
    cout << countNoZeroNumbers(21);
    return 0;
}