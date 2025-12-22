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
        int n,k;
        cin>>n>>k;
        vi vec1(n);
        forl
        {
            cin>>vec1[i];
        }
        bool found=false;
        forl
        {
            if(vec1[i]==k)
            found=true;
        }
        cout<<(found ? "YES":"NO")<<nl;
        
    }
    return 0;
}