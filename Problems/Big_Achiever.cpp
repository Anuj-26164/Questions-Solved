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
        int n,max;
        cin>>n;
        vi arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(i==0)
            {
                max=arr[0];
                cout<<1<<" ";
            }
            else
            {
                if(max<arr[i])
                {
                    cout<<1<<" ";
                    max=arr[i];
                }
                else
                {cout<<0<<" ";}
            }

        }
        cout<<nl;

    }
    return 0;
}