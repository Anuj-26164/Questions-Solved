#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec(4);
    for(int i=0;i<4;i++)
    {
        int x;cin>>x;
        vec.push_back(x);
    }
    cout<<15-accumulate(vec.begin(),vec.end(),0);
    return 0;
}