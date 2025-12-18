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
        int arr[81],k=1;
        while(k<=81)
        {for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                arr[k]=i*j;
                k++;
            }
        }
        }
        int n,sum=0;
        cin>>n;
        for(int i=1;i<=81;i++)
        {
            if(arr[i]==n)
            {
                continue;
            }
            else
            {
                sum+=arr[i];
            }
        }
        cout<<sum<<nl;
    return 0;
}