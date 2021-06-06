#include <bits/stdc++.h>
#define N 300002
using namespace std;
vector<int> d(N),g[N];
vector<bool> visited(N);
void dfs(int s,int dist)
{
	for(auto i:g[s])
	{
		if(!visited[i])
		{
			d[i]=dist+1;
			visited[i]=true;
			dfs(i,d[i]);
		}
	}
}
int main()
{
	int u,v,n;
	scanf("%d",&n);
	if(n<=1)
	{
		printf("0\n");
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	d.resize(n+1);
	visited.resize(n+1);
	d[1]=0;
	visited[1]=true;
	dfs(1,0);
	int end = distance(d.begin(),max_element(d.begin(),d.end()));
	visited.assign(visited.size(),0);
	d.assign(d.size(),0);
	visited[end]=1;
	d[end]=0;
	dfs(end,0);
	int diam = *max_element(d.begin(),d.end());
	printf("%d\n",3*diam);
	return 0;
}
