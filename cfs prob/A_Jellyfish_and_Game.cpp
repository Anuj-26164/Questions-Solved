#include <bits/stdc++.h>
using namespace std;

#define vi vector <long long int>
#define lli long long int
#define forl for(int i=0;i<n;i++)
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        lli n,m,k,sum=0;
        cin>>n>>m>>k;
        vi jelly(n),gelly(m);
        for(lli i=0;i<n;i++)
        {
            cin>>jelly[i];
        }
        for(lli i=0;i<m;i++)
        {
            cin>>gelly[i];
        }
        sort(jelly.begin(),jelly.end());
        sort(gelly.begin(),gelly.end());
        if(jelly[0]<gelly[m-1])
        {
            swap(jelly[0],gelly[m-1]);
        }
        sort(jelly.begin(),jelly.end());
        sort(gelly.begin(),gelly.end());
        if(k%2!=0)
        {
            for (lli i = 0; i < n; i++)
            {
                sum+=jelly[i];
            }
        }
        if(gelly[0]<jelly[n-1])
        {
            swap(gelly[0],jelly[n-1]);
        }
        if(k%2==0)
        {
            for (lli i = 0; i < n; i++)
            {
                sum+=jelly[i];
            }
        }
        cout<<sum<<nl;

        
    }
    return 0;
}