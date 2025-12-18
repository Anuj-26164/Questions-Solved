#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define lli long long int
#define forl for(int i=0;i<n;i++)
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        lli a,b,n,totalsum=0;
        cin>>a>>b>>n;
        vector <lli> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        totalsum+=b;
        for(int j=0;j<n;j++)
        {
            totalsum+=min(arr[j]+1,a)-1;
        }
        cout<<totalsum<<nl;
    }
    return 0;
}