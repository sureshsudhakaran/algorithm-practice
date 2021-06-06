#include<bits/stdc++.h>
#define INF 1000000009
using namespace std;
int dp[5002][5002]; //dp [i][j] refers to the cost it would take to visit j cities from i.
int pr[5002][5002];
int u,v,w,n,m,T;
vector<pair<int,int>> g[5001];
vector<int> ls;
int f(int s,int d)
{
	if(d<0) return INF;
	if(d==0)
	{
		if(s==0)
			return 0;
		return INF;
	}
	if(dp[s][d]!=-1)
		return dp[s][d];
	int dist,best = INF;
	for(auto i:g[s])
	{
		dist = f(i.first,d-1)+i.second;
		if(best>dist)
		{
			best=dist;
			pr[s][d]=i.first;
		}
	}
	if(best>T)
		best=INF;
	return dp[s][d]=best;
}
int main()
{
	cin>>n>>m>>T;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		u--,v--;
		g[v].push_back(make_pair(u,w));
	}
	for(int i=0;i<n;i++)
	{
		//dp[i][0]=0;
		for(int j=0;j<n;j++)
			dp[i][j]=-1;
	}
	int p=n-1,bi=0,best = INF;
	for(int i=0;i<n;i++)
		if(f(n-1,i)<=T)
			bi=i;
	cout<<bi+1<<"\n";
	int pos = n-1;
	while(pos!=0)
	{
		ls.push_back(pos);
		pos=pr[pos][bi];
		bi--;
	}
	ls.push_back(0);
	reverse(ls.begin(),ls.end());
	for(auto i:ls)
		cout<<i+1<<" ";
	return 0;
}
