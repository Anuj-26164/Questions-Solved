#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int count = 0;
    bool lucky = true;
    for (auto c : s)
    {
        if (c == '4' || c == '7')
        {
            count++;
        }
    }
    int temp = count;
    while (temp > 0)
    {
        int digit = temp % 10;
        if (digit == 1 || digit == 2 || digit == 3 || digit == 5 || digit == 6 || digit == 8 || digit == 9 || digit == 0)
        {
            lucky = false;
            break;
        }
        temp /= 10;
    }
    cout << ((lucky && count!=0) ? "YES" : "NO");
    return 0;
}