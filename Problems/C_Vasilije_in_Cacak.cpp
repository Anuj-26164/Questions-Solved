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
        lli n,k,x;
        cin>>n>>k>>x;
        lli minsum=0,maxsum=0;
        for(int i=1;i<=k;i++)
        {
            minsum+=i;
        }
        for(int i=n-k+1;i<=n;i++)
        {
            maxsum+=i;
        }
        if(minsum<=x && x<=maxsum)
        {
            cout<<"YES"<<nl;
        }
        else
        {
            cout<<"NO"<<nl;
        }
        
    }
    return 0;
}