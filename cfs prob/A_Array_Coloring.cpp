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
        int n,ec=0,oc=0;
        cin>>n;
        vi vec1(n);
        forl
        {cin>>vec1[i];}
        forl
        {
            if(vec1[i]%2==0)
            {
                ec++;
            }
            else
            {
                oc++;
            }
        }
        if(oc%2!=0)
        {
            cout<<"NO"<<nl;
        }
        else
        {
            cout<<"YES"<<nl;
        }

    }
    return 0;
}