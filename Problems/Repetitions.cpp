#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int count=1,maxcount=0;
    for(int i=0;i<=s.length()-1;i++)
    {
        if(s[i]==s[i+1])
        {
            count++;
        }
        else
        {
            if(count>maxcount)
            {
                maxcount=count;
            }
            count=1;
        }
    }
    cout<<maxcount;
    return 0;
}