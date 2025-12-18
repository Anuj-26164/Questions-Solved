#include <bits/stdc++.h>
using namespace std;

#define vi vector <int>
#define lli long long int
#define forl for(int i=0;i<n;i++)
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int sum=0;
        char target[10][10];
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                cin>>target[i][j];
            }
        }
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(target[i][j]=='X')
                {
                    if(i==0 || i==9 || j==0 || j==9)
                    {
                        sum+=1;
                    }
                    if((i==1||i==8) && j>=1 && j<=8)
                    {
                        sum+=2;
                    }
                    if((j==1 || j==8)&& i>=2 && i<=7)
                    {
                        sum+=2;
                    }
                    if((i==2||i==7) && j>=2 && j<=7)
                    {
                        sum+=3;
                    }
                    if((j==2 || j==7)&& i>=3 && i<=6)
                    {
                        sum+=3;
                    }
                    if((i==3||i==6) && j>=3 && j<=6)
                    {
                        sum+=4;
                    }
                    if((j==3 || j==6)&& i>=4 && i<=5)
                    {
                        sum+=4;
                    }
                    if((i==4 || i==5)&& j>=4 && j<=5)
                    {
                        sum+=5;
                    }


                }
            }
        }
        cout<<sum<<nl;

    }
    return 0;
}