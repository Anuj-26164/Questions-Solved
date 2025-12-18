#include <bits/stdc++.h>
using namespace std;
int a, b, T;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        cout << a * b / __gcd(a, b) << endl;
    }
}