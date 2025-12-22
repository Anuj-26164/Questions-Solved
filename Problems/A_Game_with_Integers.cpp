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
        int n,count=0;
        cin>>n;
        bool win=true;
        while(count<=10)
        {
            count++;
            if(n%3==0)
            {
                win=false;
            }
        }
        cout<<(win ? "First" : "Second")<<endl;
        
    }
    return 0;
}