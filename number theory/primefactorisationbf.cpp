#include <bits/stdc++.h>
using namespace std;
void Primefact(int N)
{
    for (int i=2;i<=N;i++)
    {
        if(N%i==0)
        {
            int count=0;
            while(N%i==0)
            {
                count++;
                N=N/i;//most important step
            }
            cout<<i<<"^"<<count<<" ";
        }
    }
    
}


int main() {
    Primefact(14);
    
    return 0;
}