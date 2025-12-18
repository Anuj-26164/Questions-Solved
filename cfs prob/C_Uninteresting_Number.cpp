#include <bits/stdc++.h>
using namespace std;

int main() {
    int i;
    cin>>i;
    while(i)
    {
        string s;
        cin>>s;
        int count2=0,count3=0,sumofdig=0;
        for (int i=0;i<s.size();i++)
        {
            if(s[i]=='2')
            {
                count2++;
            }
            if(s[i]=='3')
            {
                count3++;
            }
        }
        for (int i=0;i<s.size();i++)
        {
            sumofdig+=s[i]-'0';
        }
        for(int i=0;i<=count2;i++)
        {
            for(int j=0;j<=count3;j++)
            {
                sumofdig+=2*i + 6*j;
            }
            if(sumofdig%9==0)
            {
                cout<<"YES"<<endl;
                goto x;
            }
        }
        cout<<"NO"<<endl;

        x:



    i--;
    }
    return 0;
}