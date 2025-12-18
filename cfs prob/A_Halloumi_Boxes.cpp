#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int i;
    cin >> i;
    while (i) {
        int n,k;
        cin>>n;
        cin>>k;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        if(k>1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            for(int i=0;i<n-1;i++)
            {
            if(arr[i+1]<arr[i])
            {
                cout<<"NO"<<endl;
                goto x;
            }
            }
            cout<<"YES"<<endl;
        }
        x:
        i--;
    }
    return 0;
}