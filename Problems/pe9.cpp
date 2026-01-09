#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N = 1000;
    for (int m = 2; m * m <= N; m++)
    {
        for (int n = 1; n < m; n++)
        {
            if (__gcd(m, n) == 1 && ((m - n) % 2))
            {
                int a = m * m - n * n;
                int b = 2 * m * n;
                int c = m * m + n * n;
                for (int k = 1; k * c <= N; k++)
                {
                    if (k * a + k * b + k * c == 1000)
                        cout << k * k * k * a * b * c << endl;
                }
            }
        }
    }
    return 0;
}