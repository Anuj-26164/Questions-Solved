#include <bits/stdc++.h>
using namespace std;
const int m=1e7+7;
int fact(int n)
{
    int i=n;
    if(i==1)
    {
        return 1;
    }
    else
    return (fact(n-1)%m)*(n%m);
}

int main() {
    cout<<fact(10);
    
    return 0;
}