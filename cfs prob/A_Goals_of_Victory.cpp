#include <bits/stdc++.h>
using namespace std;

#define vi vector <int>
#define lli long long int
#define forl for(int i=0;i<n;i++)
#define nl '\n'
int sum(int arr[],int size,int i)
{
    if(i<0)
    {
        return 0;
    }
    else
    {
        return arr[i]+sum(arr,size,i-1);
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        int arr[n-1];
        for(int i=0;i<n-1;i++)
        {
            cin>>arr[i];
        }
        int sumi=-sum(arr,n-1,n-2);
        cout<<sumi<<nl;
    }
    return 0;
}