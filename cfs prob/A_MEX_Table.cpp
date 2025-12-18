#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define lli long long int
#define forl for(int i=0;i<n;i++)
#define nl '\n'

int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        if(n==m)
        {
            cout<<n+1<<nl;
        }
        else
        {
            cout<<(n>m? n+1:m+1)<<nl;
        }
    }
    return 0;
}