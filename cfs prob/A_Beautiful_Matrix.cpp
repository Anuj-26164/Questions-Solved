#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5][5];
    int k=0,l=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            int x;
            cin>>x;
            arr[i][j]=x;
            if(x==1)
            {
                k=i,l=j;
            }
        }
    }
    cout<<abs(2-k)+abs(2-l);
    return 0;
}