#include <bits/stdc++.h>
using namespace std;
void isprime(int N)
{
    for(int i=2;i*i<=N;i++)
    {
        if(N%i==0)
        {
            cout<<"NOT PRIME"<<endl;
            break;
        }
    }
    cout<<"PRIME";
}

int main() {
    isprime(19);
    
    return 0;
}