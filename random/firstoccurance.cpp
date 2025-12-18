#include <bits/stdc++.h>
using namespace std;
int lastocurr(int arr[],int size,int i,int target)
{
    if(i<0)
    {
        return -1;
    }
    if(arr[i]==target)
    {
        return i;
    }
    else
    {
        return lastocurr(arr,size,i-1,target);
    }
}

int main() {
    int arr[7]={1,2,2,2,3,3,4};
    cout<<lastocurr(arr,7,6,2);
    
    return 0;
}