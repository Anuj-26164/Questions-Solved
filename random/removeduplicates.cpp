#include <bits/stdc++.h>
using namespace std;
int f(int n)
{
    if(n==1) return 2;
    if(n==2) return 3;

    return f(n - 1) + f(n - 2);
}

int main()
{

    return 0;
}