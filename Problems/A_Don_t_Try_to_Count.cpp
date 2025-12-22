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
        int n,m,k=0;
        cin>>n>>m;
        string x,s;
        cin>>x>>s;
        while(x.size()<=s.size())
        {
        size_t pos=x.find(s,0);
        if(pos==string::npos)
        {
            x.append(x);
            k++;
        }
        else
        {
            cout<<k<<endl;
            break;
        }
        }
        

    }
    return 0; 
}