//https://codeforces.com/contest/1253/problem/D
#include <bits/stdc++.h>
using namespace std;
int parent[200001]={0};
int n,m;
int Find(int x){
    if(x!=parent[x]) parent[x]=Find(parent[x]);
    return parent[x];
}
void join(int i,int j)
{
	int p=Find(i),q=Find(j);
	if(p==q) return;
	if(p>q) parent[q]=p;
	else parent[p]=q;
}
int main()
{
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=n;i++)
		parent[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		join(u,v);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int m3,mx2,mx=Find(i);
		if(mx!=i)
		{
			for(int j=i+1;j<=mx;j++)
			{
				mx2=Find(j);
				if(mx2!=mx)
				{
					ans++;
					join(mx2,mx);
					mx=Find(i);
				}
			}
		}
		i=mx;
	}
	cout<<ans<<endl;
	return 0;
}
