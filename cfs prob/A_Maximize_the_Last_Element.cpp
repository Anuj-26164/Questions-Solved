// Qs: A_Maximize_the_Last_Element
// Time: 13:57:38

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
        ll n;cin>>n;
        vl arr(n);
        for(auto &c:arr) cin>>c;
        ll maxElement=minval;
        for(int i=0;i<n;i+=2)
        {
            maxElement=max(maxElement,arr[i]);
        }
        cout<<maxElement<<nl;
    }
    return 0;
}