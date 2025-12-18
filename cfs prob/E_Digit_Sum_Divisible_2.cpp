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
    string s;
    int sum=0;
    cin>>s;
    lli num=stoi(s);
    for(int i=0;i<s.size();i++)
    {
        sum+=(s[i]-'0');

    }
    if(num%sum==0)
    return 0;
}