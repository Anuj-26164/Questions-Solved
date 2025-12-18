#include <bits/stdc++.h>
using namespace std;

#define vi vector <int>
#define lli long long int
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        double k,l1,r1,l2,r2,y;
        int n=0,count=0;
        cin>>k>>l1>>r1>>l2>>r2;
        n=(log(r2)-log(l1))/log(k);   
        cout << (n+1)*(r1-l1) <<nl;
    }
    return 0;
}