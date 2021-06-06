//https://codeforces.com/contest/1253/problem/A
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
int main()
{
	int a[MAXN],b[MAXN],n,t,diff[MAXN];
	bool flag;
	cin>>t;
	while(t--)
	{
		flag = false;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		for(int i=0;i<n;i++)
		{
			if(a[i]>b[i])
			{
				cout<<"NO\n";
				flag = true;
				break;
			}
			diff[i]=b[i]-a[i];
		}
		if(!flag)
		{
			int d,i=0;
			while((i<n)&&(diff[i]==0))
				i++;
			if(i==n)
				cout<<"YES\n";
			else
			{
				d=diff[i];
				while((i<n)&&(diff[i]==d))
					i++;
				if(i==n)
					cout<<"YES\n";
				else
				{
					while((i<n)&&(diff[i]==0))
					i++;
					if(i==n)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
			}
		}
	}
	
}
