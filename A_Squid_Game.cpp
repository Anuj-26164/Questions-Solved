#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k,n) for(int i=k;i<n;i++)
#define nkinput() int n,k;cin>>n;cin>>k;
#define ninput() int n;cin>>n;
#define arrinput() vl arr(n);for(auto &c:arr) cin>>c;
#define forl for(int i=0;i<n;i++)
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        vl arr(3);
        for (auto &c : arr) cin >> c;
        sort(arr.begin(), arr.end());
        
        if (arr[0] + arr[1] > arr[2]) {
            cout << 0 << nl; 
        } else {
            cout << arr[2] - (arr[0] + arr[1]) + 1 << nl;
        }
    }
    return 0;
}

