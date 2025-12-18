#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> arr(n);
        for(auto &c: arr) cin >> c;
        for(int i=0;i<n-1;i++){
            if(arr[i] <=arr[i+1]){
                long long temp = arr[i];
                arr[i] =0;
                arr[i+1] -= temp;
            }
        }
        bool ok=true;
        for(int i=0;i<n-1;i++) if(arr[i] >arr[i+1]){
            ok=false;
            break;
        }
        if(ok) cout << "YES"<<endl;
        else cout << "NO"<<endl;
    }
}