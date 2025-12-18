#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]-'0'>4 )
        {
            if(i==0 && s[i]=='9')
            {
                continue;

            }

            else
            s[i]='9'-(s[i]-'0');
        }
    }
    cout<<s;
    return 0;
}