#include <bits/stdc++.h>
using namespace std;
int sum(int a, int b)
{
    return (a | b) + (a & b);
}
int main()
{
    cout << sum(5, 4);
    return 0;
}