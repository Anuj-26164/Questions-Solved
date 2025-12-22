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
        int n;
        cin>>n;
        if(n%2==0)
        {
            cout<<(n-2)+1<<nl;
        }
        else
        {
            cout<<(n-1)<<nl;
        }
    }
    return 0;
}