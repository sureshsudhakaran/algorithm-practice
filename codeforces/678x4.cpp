#include <bits/stdc++.h>
#define SIZE 200004
using namespace std;
vector<int> g[SIZE];
bool isleaf[SIZE]={0};
long long pplblw[SIZE]={0};
int nblw[SIZE]={0};
int a[SIZE]={0};
pair<long long,int> dfs(int x)
{
	pplblw[x]=a[x];
	nblw[x]=isleaf[x]?1:0;
	pair<long long,int> d;
	for(auto i:g[x])
	{
		d=dfs(i);
		pplblw[x]+=d.first;
		nblw[x]+=d.second;
	}
	return make_pair(pplblw[x],nblw[x]);
}
int main()
{
	int n,x;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		cin>>x;
		g[x].push_back(i);
	}
	for(int i=1;i<=n;i++)
	cin>>a[i];
	a[0]=0;
	for(int i=1;i<=n;i++)
		isleaf[i]=(g[i].size()==0)?1:0;
	dfs(1);
	long long m,mx=-1;
	for(int i=1;i<=n;i++)
	{
		m=(pplblw[i]+nblw[i]-1)/(nblw[i]);
		if(mx<m)
		mx=m;
	}
	cout<<mx<<"\n";
	return 0;
}
