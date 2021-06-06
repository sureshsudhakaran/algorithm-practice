#include <bits/stdc++.h>
using namespace std;
struct pr
{
	int val;
	int index;
	bool operator<(pr &a)
	{
		return val==a.val?index>a.index:val<a.val;
	}
	
}a[102],c[102];

bool cmp(pr &a,pr &b)
{
	return a.index<b.index;
}

int main()
{
	int m,n,k,p;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].val;
		a[i].index=i;
	}
	sort(a,a+n);
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>k>>p;
		for(int j=n-1;j>n-k-1;j--)
			c[n-1-j]=a[j];
		sort(c,c+k,cmp);
		cout<<c[p-1].val<<endl;
	}
	return 0;
}
