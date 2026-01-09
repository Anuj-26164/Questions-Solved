#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 0;
    for (long long i = 10000000000; i >= 1; i--)
    {
        if (i % 16 == 0 && i % 9 == 0 && i % 5 == 0 && i % 7 == 0 && i % 11 == 0 && i % 13 == 0 && i % 17 == 0 && i % 19 == 0)
        {
            ans = i;
        }
    }
    cout << ans << "\n";
    return 0;
}