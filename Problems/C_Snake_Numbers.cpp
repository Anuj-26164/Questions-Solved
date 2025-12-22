#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define lli long long int
#define forl for(int i=0;i<n;i++)
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    lli l,r,count=0;
    cin>>l>>r;
    for(lli i=l;i<=r;i++)
    {
        lli temp=i;
        vi arr;
        while(temp)
        {
            
            arr.push_back(temp%10);
            temp/=10;

        }
        for(int j=0;j<arr.size();j++)
        {
            if(arr[j]>=arr[arr.size()-1] && j!=arr.size()-1)
            {
                break;
            }
            if(j==arr.size()-1)
            {
                count++;
            }

            
        }
    }
    cout<<count<<nl;

    return 0;
}