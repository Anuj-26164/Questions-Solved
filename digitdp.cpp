#include <bits/stdc++.h>
using namespace std;

long long dp[20][200][2];

void getDigits(long long x, vector<int> &digit)
{
    while (x > 0)
    {
        digit.push_back(x % 10);
        x /= 10;
    }
    if (digit.empty())
        digit.push_back(0);              // for case x=0
    reverse(digit.begin(), digit.end()); // store in MSD → LSD order
}

long long digitSum(int idx, int sum, int tight, vector<int> &digit)
{
    if (idx == digit.size())
        return sum; // base case

    if (dp[idx][sum][tight] != -1)
        return dp[idx][sum][tight];

    int limit = tight ? digit[idx] : 9;
    long long res = 0;

    for (int d = 0; d <= limit; d++)
    {
        res += digitSum(idx + 1, sum + d, tight && (d == limit), digit);
    }

    return dp[idx][sum][tight] = res;
}

long long rangeDigitSum(long long a, long long b)
{
    vector<int> digit;

    // sum(1..b)
    getDigits(b, digit);
    memset(dp, -1, sizeof(dp));
    long long ans2 = digitSum(0, 0, 1, digit);

    // sum(1..a-1)
    if (a > 0)
    {
        digit.clear();
        getDigits(a - 1, digit);
        memset(dp, -1, sizeof(dp));
        long long ans1 = digitSum(0, 0, 1, digit);
        return ans2 - ans1;
    }
    return ans2;
}

int main()
{
    long long a = 0, b = 10LL;
    cout << "digit sum for given range: " << rangeDigitSum(a, b) << "\n";
    return 0;
}
