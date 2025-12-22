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
        int n,k,j,m=1;
        
        cin>>n>>k;
        vi arr(n,0);
        for(int i=k-1;i<n;i+=k)
        {
            arr[i]=m;
            m++;
        }
        j=m;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {arr[i]=j;
            j++;}
        }
        for(auto c:arr)
        {
            cout<<c<<" ";
        }
        cout<<nl;

    }
    return 0;
}