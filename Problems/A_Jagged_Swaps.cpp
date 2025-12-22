#include <bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int i=0;i<n;i++)
#define lli long long int

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        bool marked=false;
        for(int i=1;i<n;i++){
            if(arr[i]<arr[0])marked=true;
        }
        if(marked==true)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}