#include <bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int i=0;i<n;i++)
#define lli long long int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int i;
    cin >> i;
    while (i--) {
        int n,x,maxdiff=1,first,last;
        cin>>n>>x;
        vector <int> vec1(n);
        loop(i,n)
        {
            cin>>vec1[i];
        }
        loop(i,n-1)
        {
            maxdiff=max(vec1[i+1]-vec1[i],maxdiff);
        }
        first=vec1[0];
        last=2*(x-vec1[n-1]);
        maxdiff=max(first,max(last,maxdiff));
        cout<<maxdiff<<endl;

    }
    return 0;
}