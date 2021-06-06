#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,n,m,T;
	long sum;
	cin>>T;
	while(T--)
	{
		sum=0;
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			sum+=a;
		}
		if(sum==m)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	return 0;
}
