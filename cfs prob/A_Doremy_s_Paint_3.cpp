#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define lli long long int
#define nl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi vec1(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec1[i];
        }
        int diffcount = 1,alpha=0,beta=0,count1=0,count2=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                    if(vec1[i]!=vec1[j])
                    {
                        diffcount++;
                        break;
                    }
            }
        }
        cout<<diffcount<<nl;
        bool good;
        if(!(diffcount==2 || diffcount==1))
        {
            good=false;
        }
        if(diffcount==1)
        {
            good=true;
        }
        if(diffcount==2)
        {
            for(int i=0;i<n-1;i++)
            {
                if(vec1[i]!=vec1[i+1])
                {
                    alpha=vec1[i];
                    beta=vec1[i+1];
                    break;
                }

            }
            for(int i=0;i<n;i++)
            {
                if(vec1[i]==alpha)
                {
                    count1++;
                }
                else
                {
                    count2++;
                }
            }
            cout<<count1<<nl;
            cout<<count2<<nl;

            if(n%2==0 && count1==count2)
            good=true;
            if(n%2!=0 && abs(count1 - count2)==1)
            {
                good=true;
            }

        }

        cout << (good ? "Yes" : "No") << nl;
    }
    return 0;
}