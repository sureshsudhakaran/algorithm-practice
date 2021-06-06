#include<bits/stdc++.h>
using namespace std;
const int SIZE = 100001;
vector<int> v;
long long cost(int p)
{
	int median;
	long long c=0;
	for(int i=0;i<v.size();i+=p)
	{
		median = v[(i+i+p-1)/2];
		for(int j=i;j<i+p;j++)
		c+=abs(v[j]-median);
	}
	return c;
}
int main()
{
	int a[SIZE],n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			v.push_back(i);
	}
	long long c=LONG_LONG_MAX;
	if(v.size()==1)
		cout<<-1<<endl;
	else
	{
		int tmp=v.size();
		for(int i=2;i*i<=tmp;i++)
		{
			if(tmp%i==0)
			{
				c=min(c,cost(i));
				while(tmp%i==0)
				tmp/=i;
			}
		}
		if(tmp>1)
		c=min(c,cost(tmp));
		cout<<c<<endl;
	}
	return 0;
}
