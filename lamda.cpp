#include <bits/stdc++.h>
using namespace std;

int main() {
    auto cmp=[](long long x,long long y){return x<y;};
    vector <long long> v{23,21,3,5,1,981,921};
    sort(v.begin(),v.end(),cmp);
    for_each(v.begin(),v.end(),[](long long x){cout<<x<<endl;});
    return 0;
}