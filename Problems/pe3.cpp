#include <bits/stdc++.h>
using namespace std;

bool isprime(long long j)
{
    for (long long i = 2; i * i <= j; i++)
        if (j % i == 0)
            return false;
    return true;
}
int main()
{
    long long x = 600851475143, ans;
    for (long long i = 2; i * i <= x; i++)
    {
        if (isprime(i) && x % i == 0)
            ans = i;
    }
    cout << ans;
    return 0;
}