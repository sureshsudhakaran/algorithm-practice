//https://codeforces.com/contest/1253/problem/F
#include <bits/stdc++.h>
using namespace std;
struct pr
{
	int node;
	int weight;
	bool operator<(pr a){ return a.weight <  weight; }
	pr(int a,int b){node=a;weight=b;}
};
struct res
{
	bool anc;
	int wgt;
};
vector<pr> g[100002];
int clo[100002]={0};
int dist[100002];
void dijkstra(int a)
{
	priority_queue<pr> al;
	dist[a]=0;
	pr x(a,0);
	al.push_back(x);
	while(!al.empty())
	{
		pr b=al.pop();
		for(auto i:g[b.node])
		{
			if(dist[i.node]>b.weight+i.weight)
			{
				dist[i.node]=b.weight+i.weight;
				clo[i.node]=b.node;
				pr y(i.node,dist[i.node]);
				al.push_back(y);
			}
		}
	}
}

vector<int> tin, tout;
int timer,l;
vector<vector <int> > up;
vector<vector <int> > wt;

void dfs(int v, int p, int w)
{
	tin[v]= ++timer;
	up[v][0] = p;
	wt[v][0] = w;
	for(int i=1;i<=l;i++) {
		up[v][i] = up[up[v][i-1]][i-1];
		wt[v][i] = max(w,wt[up[v][i-1]][i-1]);
	}
	for (auto u : g[v]) {
        if (u.node != p)
            dfs(u.node, v,u.weight);
    }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int main()
{
	int n,m,k,q,u,v,w;
	cin>>n>>m>>k>>q;
	for(int i=1;i<=n;i++)
		dist[i]=INT_MAX;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		pr x(u,w);
		g[v].push_back(x);
		x.node=v;
		g[u].push_back(x);
	}
	for(int i=1;i<=k;i++)
		dijkstra(i);
	//Binary lifting and kruskal needed.
	
	for(int i=1;i<=n;i++)
		for(int j=0;j<g[i].size();j++)
			g[i].weight = g[i].weight + dist[i] + dist[g[i].node];

	tin.resize(n);
	tout.resize(n);
	timer = 0;
	l = ceil(log2(n));
	up.assign(n, vector<int>(l + 1));
	wt.assign(n, vector<int>(l + 1,0));
	return 0;
}
