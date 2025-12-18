#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {
    lli n;
    cin>>n;
    lli arr[n],moves=0;
    for(lli i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(lli i=0;i<=n-2;i++)
    {
        if(arr[i]>arr[i+1])
        {
            moves+=arr[i]-arr[i+1];
            arr[i+1]=arr[i];

        }
        

    }
    cout<<moves;

    return 0;
}