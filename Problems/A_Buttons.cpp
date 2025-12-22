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
        lli a,b,c;
        cin>>a>>b>>c;
        if((a+b+c)%2==0)
        {
            cout<<"Second";
        }
        else
        cout<<"First";
        cout<<nl;
        
    }
    return 0;
}