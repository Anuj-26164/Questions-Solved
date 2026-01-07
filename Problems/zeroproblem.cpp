#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0;
    for (long long i = 1; i <= 999000;i++)
    {
        if((i*i)%2)
            ans += i * i;
    }
    cout << ans;
    return 0;
}