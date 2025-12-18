#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n = 11;
    while (1)
    {
        long long temp;
        temp = n;
        long long lastDig = temp % 10;
        temp /= 10;
        long long temp1 = log10(temp) + 1;

        long long newNum = ((int)pow(10, temp1)) * lastDig + temp;
        if (newNum == 2 * n)
        {
            cout << n;
            break;
        }
        n++;
    }
    return 0;
}