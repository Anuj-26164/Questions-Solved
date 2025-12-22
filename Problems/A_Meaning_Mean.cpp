// Qs: A_Meaning_Mean
// Time: 16:35:35

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
        f(0,n) cin>>arr[i];
        sort(arr.begin(),arr.end());
        ll sum=(arr[0]+arr[1])/2;
        if(n>1)
        {
            f(2,n)
            {
                sum=(sum+arr[i])/2;
            }
        }
        cout<<sum<<nl;
    }
    return 0;
}