#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define lli long long int
#define forl for(int i=0;i<n;i++)
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n,k=0;
        cin>>n;
        string x,y;
        cin >> x;
        cin>>y;
        forl
        {
            if(x[i]=='1' && y[i]=='1')
            {
                k++;
            }
        }
        forl
        {
            if(k%2==0)
            {
                if((x[i]=='1' && y[i]=='0') || (x[i]=='0' && y[i]=='1'))
                {
                    k++;
                }
            }
            if(x[i]=='0' && y[i]=='0')
            {
                continue;
            }
            

        }
    
        cout<<(k%2!=0 ? "YES" : "NO")<<nl;
    }
    return 0;
}