// Qs: A_Denial
// Time: 15:02:00

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k,n) for(int i=k;i<n;i++)
#define nl '\n'


void yes() {
    cout << "YES" << endl;
}

void no() {
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll x,y;cin>>x>>y;
        ll z=lcm(360,y)/y;
        cout<<x*z<<nl;
    }
    return 0;
}