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
        int n,k,letterodd=0;
        cin>>n>>k;
        string s;
        cin>>s;
        int arr[26]={0};
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]%2!=0)
            {
                letterodd++;
            }
        }
        cout<<(letterodd>k+1? "NO" : "YES")<<nl;
    }

        

    return 0;
}