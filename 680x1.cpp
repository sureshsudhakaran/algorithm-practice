#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tm,n,x,T;
	cin>>T;
	vector<int> a,b;
	while(T--)
	{
		a.clear();
		b.clear();
		cin>>n>>x;
		for(int i=0;i<n;i++)
		{
			cin>>tm;
			a.push_back(tm);
		}
		for(int i=0;i<n;i++)
		{
			cin>>tm;
			b.push_back(tm);
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end(),greater<int>());
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]+b[i]>x)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		cout<<"No\n";
		else
		cout<<"Yes\n";
	}
	return 0;
}
