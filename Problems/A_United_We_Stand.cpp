#include <bits/stdc++.h>
using namespace std;

#define vi vector <int>
#define lli long long int
#define forl for(int i=0;i<n;i++)
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n,k=0,j=0;
        cin>>n;
        vi vec1(n);
        forl
        {cin>>vec1[i];}
        sort(vec1.begin(),vec1.end(),greater<int>());
        for(int i=0;i<n-1;i++)
        {
            if(vec1[i]!=vec1[i+1])
            {
                k=vec1[i];
                j=i;
                break;
            }
        }
        if(k==0)
        {
            cout<<-1<<nl;

        }
        else
        {
            cout<<n-j-1 <<" "<<j+1<<nl;
            for(int i=j+1;i<n;i++)
            {
                cout<<vec1[i]<<" ";
            }
            cout<<nl;
            for(int i=0;i<=j;i++)
            {cout<<k<<" ";}
            cout<<nl;
            
        }
    }
    return 0;
}