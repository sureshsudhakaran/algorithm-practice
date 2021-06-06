#include <bits/stdc++.h>
#define N 300002
using namespace std;
vector<int> d(N),d2(N),g[N];
vector<bool> visited(N);
void dfs(vector<int> &d,int s)
{
	for(auto i:g[s])
	{
		if(!visited[i])
		{
			d[i]=d[s]+1;
			visited[i]=true;
			dfs(d,i);
		}
	}
}
int main()
{
	int u,v,n;
	scanf("%d",&n);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	d.resize(n+1);
	d2.resize(n+1);
	visited.resize(n+1);
	d[1]=0;
	visited[1]=true;
	dfs(d,1);
	int end = distance(d.begin(),max_element(d.begin(),d.end()));
	visited.assign(visited.size(),0);
	d.assign(d.size(),0);
	visited[end]=1;
	d[end]=0;
	dfs(d,end);
	auto tmp = max_element(d.begin(),d.end());
	int diam = *tmp;
	int end2 = distance(d.begin(),tmp);
	visited.assign(visited.size(),0);
	visited[end2]=1;
	d[end2]=0;
	dfs(d2,end2);
	d[end2]=diam;
	for(int i=1;i<=n;i++)
	{
		if(max(d[i],d2[i])==diam)
			printf("%d\n",diam+1);
		else
			printf("%d\n",diam);
	}

	return 0;
}
