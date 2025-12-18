#include <bits/stdc++.h>
using namespace std;
long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    long long n,y,sum=0;
    cin>>n;
    if(n%2==0)
    {
        for(int i=0;i<=n;i+=2)
        {
            y=(n-i)/2;
            sum+=(factorial(i+y))/(factorial(i)*factorial(y));
        }

    }
    else
    {
        for(int i=1;i<=n;i+=2)
        {    y=(n-i)/2;
            sum+=(factorial(i+y))/(factorial(i)*factorial(y));

        }
    }
    cout<<sum;
    return 0;
}