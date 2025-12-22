
///////////
#include <bits/stdc++.h>
using namespace std;

int main() {
    int i;
    cin>>i;
    while(i)
    {
        int n,sum=0,sumodd=0,sumeven=0;
        cin>>n;
        vector <int> vec1(n);
        for(int num : vec1)
        {
            cin>>num;
        }
        for(int num : vec1)
        {
            sum+=num;
        }
        if(sum%n!=0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            int j=sum/n;
            for(int i=0;i<vec1.size();i+=2)
            {
                sumeven+=vec1[i];
            }
            for(int i=1;i<vec1.size();i+=2)
            {
                sumodd+=vec1[i];
            }
            sumeven/=(n/2);
            int k=n/2;
            sumodd/=(n-k);
            if(sumeven==j && sumodd==j)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    i--;
    }
    return 0;
}