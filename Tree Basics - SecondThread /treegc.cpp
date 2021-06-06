#include<bits/stdc++.h>
using namespace std;
const int N = (int)(3e5+2);
const int LOGN = 20;
struct node
{
	pair<int,int> par[LOGN];
	vector<pair<int,int>> g;
	int tin,tout,depth;
}nd[N];
bool is_ancestor(int u, int v)
{
    return nd[u].tin <= nd[v].tin && nd[u].tout >= nd[v].tout;
}
bool visited[N+1]={0};
int counter=1;
void dfs(int s)
{
	//~ cout<<"DFS for "<<s<<endl;
	nd[s].tin=counter++;
	for(int i=1;i<LOGN;i++)
	{	
		nd[s].par[i].first=nd[nd[s].par[i-1].first].par[i-1].first;
		nd[s].par[i].second=min(nd[s].par[i-1].second,nd[nd[s].par[i-1].first].par[i-1].second);
	}
		
	for(pair<int,int> i:nd[s].g)
	{
		if(!visited[i.first])
		{
			visited[i.first]=true;
			nd[i.first].depth=nd[s].depth+1;
			nd[i.first].par[0].first=s;
			nd[i.first].par[0].second=i.second;
			dfs(i.first);
		}
	}
	nd[s].tout=counter++;
}
int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = LOGN-1; i >= 0; --i) {
        if (!is_ancestor(nd[u].par[i].first, v))
            u = nd[u].par[i].first;
    }
    return nd[u].par[0].first;
}
int anc(int u,int dist)
{
	//cout<<"\n\n";
	int ux,u2=INT_MAX,u1=u;
	while(dist)
	{
		int hsb = 32-__builtin_clz(dist);
		ux=nd[u1].par[hsb-1].first;
		u2=min(u2,nd[u1].par[hsb-1].second);
		dist-=(1<<(hsb-1));
		u1=ux;
		//~ cout<<hsb<<"\t"<<dist<<endl;
		//getchar();
	}
	return u2;
}
int main()
{
	for(int i=0;i<LOGN;i++)
	{
		nd[1].par[i].first=1;
		nd[1].par[i].second=INT_MAX;
	}
	int a,b,u,v,n,q,w,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		nd[u].g.emplace_back(v,w);
		nd[v].g.emplace_back(u,w);
	}
	visited[1]=true;
	nd[1].depth=0;
	dfs(1);
	//~ cout<<"\n\ndepth\ttin\ttout\n";
	//~ cout<<nd[1].depth<<"\t"<<nd[1].tin<<"\t"<<nd[1].tout<<endl;
	//~ cout<<nd[2].depth<<"\t"<<nd[2].tin<<"\t"<<nd[2].tout<<endl;
	//~ cout<<"\n\n";
	//cout<<anc(3,1)<<endl;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&a,&b);
		int p=lca(a,b);
		//cout<<"Ancestor is "<<p<<endl;
		int left=nd[a].depth-nd[p].depth;
		int right = nd[b].depth - nd[p].depth;
		//cout<<"Ancestor is "<<p<<endl;
		int u=INT_MAX;
		if(left!=0) u=anc(a,left);
		if(right!=0) u=min(u,anc(b,right));
		printf("%d\n",u);
	}
	return 0;
}
