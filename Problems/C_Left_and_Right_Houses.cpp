#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int i;
    cin >> i;
    while (i--) {
        int n,x;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        if(n%2==0)
        {
            x=n/2;
        }
        else
        {
            x=(n+1)/2;
        }
    }
    return 0;
}