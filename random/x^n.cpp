#include <bits/stdc++.h>
using namespace std;
int pow(int base,int power)
{
    if(power==0)
    {
        return 1;
    }
    if((power&1)==0)//even
    {
        power/=2;
        base*=base;
        return pow(base,power);

    }
    else
    {
        power=(power-1)/2;
        int x=pow(base,power);
        return x*base*x;

    }
}
int main() {
    cout<<pow(2,10);
    
    return 0;
}