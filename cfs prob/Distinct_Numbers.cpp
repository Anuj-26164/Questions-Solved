// Qs: Distinct_Numbers
// Time: 00:50:43

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k,n) for(int i=k;i<n;i++)
#define nl '\n'


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin>>n;
    set<ll> ust;
    f(0,n)
    {
        ll x;cin>>x;
        ust.insert(x); 
    }
    cout<<ust.size();
    return 0;
}