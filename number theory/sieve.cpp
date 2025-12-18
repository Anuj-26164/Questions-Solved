#include <bits/stdc++.h>
using namespace std;
void PrintPrimes(int N)
{
    int arr[N+1];
    for(int i=0;i<=N+1;i++)
    {
        arr[i]=1;
    }
    arr[0]=0,arr[1]=0;
    for(int i=2;i*i<=N;i++)
    {
        if (arr[i])
        {
            for(int j=i*i;j<=N;j+=i)
            {
                arr[j]=0;
            }
        }
    }
    for(int i=2;i<=N;i++)
    {
        if(arr[i])
        {
            cout<<i<<" ";
        }
    }
}

int main() {
    PrintPrimes(1000);
    
    return 0;
}