#include <bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		int m=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<=n-2;i++)
		
		{
			b[1]=a[i],b[2]=a[i+1],b[3]=a[i+2];
			sort(b+1,b+4);
			m=max(m,b[2]);
		}
		cout<<m<<endl;
	}
	return 0;
}