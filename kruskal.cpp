#include <bits/stdc++.h>
#define SIZE 500
#define EDG 1000
using namespace std;
struct edge
{
	int first;
	int second;
	int weight;
};
bool edge_sort(edge &e1,edge &e2)
{
	return e1.weight<e2.weight;
}
int par[SIZE];
vector<edge> edglist,ktree;
int getpar(int i)
{
	if(par[i]!=i)
	par[i]=getpar(par[i]);
	return par[i];
}
int main()
{
	int n,m,u,v,w;
	edge e;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		par[i]=i;
	for(int i=0;i<m;i++){
		cin>>e.first>>e.second>>e.weight;
		edglist.push_back(e);
	}
	sort(edglist.begin(),edglist.end(),edge_sort);
	int mn,min_cost=0;
	for(auto e:edglist)
	{
		if(getpar(e.first)!=getpar(e.second))
		{
			min_cost+=e.weight;
			ktree.push_back(e);
			mn=min(par[e.first],par[e.second]);
			par[e.first]=mn;
			par[e.second]=mn;
		}
	}
	for(auto e:ktree)
		cout<<e.first<<"\t"<<e.second<<"\t"<<e.weight<<endl;
	return 0;
}
