#include<bits/stdc++.h>
#define DFS_WHITE -1
using namespace std;
const int SIZE = 500;
vector<int> g[SIZE],S;
vector<int> dfsnum,dfslow;
int counter=1,nSCC=0;
bool visit[SIZE]={};
void tarjan(int u)
{
	dfsnum[u]=dfslow[u]=counter++;
	S.push_back(u);
	visit[u]=true;
	for(auto i:g[u])
	{
		if(dfsnum[i]==DFS_WHITE)
			tarjan(i);
		if(visit[i]==true)
			dfslow[u]=min(dfslow[u],dfslow[i]);
	}
	if(dfslow[u]==dfsnum[u])
	{
		printf("SCC %d :\t",nSCC++);
		while(1)
		{
			int v = S.back();
			S.pop_back();
			visit[v]=0;
			printf("%d ",v);
			if(u==v)
			break;
		}
		printf("\n");
	}
}
int main()
{
	int n,m,u,v;
	S.clear();
	cin>>n>>m;
	dfsnum.assign(n,DFS_WHITE);
	dfslow.assign(n,0);
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
	}
	for(int i=0;i<n;i++)
	if(dfsnum[i]==DFS_WHITE)
	tarjan(i);
	cout<<endl<<endl;
	for(int i=0;i<n;i++)
	cout<<dfslow[i]<<"\t"<<dfsnum[i]<<endl;
	return 0;
}
