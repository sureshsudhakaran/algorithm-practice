#include<bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
vector<int> g[100005];
long long dp[100005][12][4]={0};
int u,v,n,m,k,x;
void dfs(int s,int par)
{
	for(auto i:g[s]){
		if(i!=par)
			dfs(i,s);
	}
	
	long long subdp[g[s].size()+1][x+1];
	{ //study more about block magic
		memset(subdp,0,sizeof(subdp));
		subdp[0][0]=1;
		// subdp [i][j] => from the first i children of node s, number of assignments that can be made with j vaults
		int cnt=0;
		for(auto i:g[s])
		{
			if(par!=i)
			{
				for(int cur=0;cur<=x;cur++)
				for(int take=0;take<=x-cur;take++)
				{
					int tot = take+cur;
					long long val = dp[i][take][0]+dp[i][take][1]+dp[i][take][2];
					subdp[cnt+1][tot]=(subdp[cnt+1][tot]+val*subdp[cnt][cur])%mod;
				}
				cnt++;
			}
		}
		for(int i=0;i<=x;i++)
		dp[s][i][0]=(subdp[cnt][i]*(k-1))%mod;
	}
	{
		memset(subdp,0,sizeof(subdp));
		subdp[0][0]=1;
		// subdp [i][j] => from the first i children of node s, number of assignments that can be made with j vaults
		int cnt=0;
		for(auto i:g[s])
		{
			if(par!=i)
			{
				for(int cur=0;cur<=x;cur++)
				for(int take=0;take<=x-cur;take++)
				{
					int tot = take+cur;
					long long val = dp[i][take][0];
					subdp[cnt+1][tot]=(subdp[cnt+1][tot]+val*subdp[cnt][cur])%mod;
				}
				cnt++;
			}
		}
		for(int i=0;i<=x-1;i++)
		dp[s][i+1][1]=subdp[cnt][i];
	}
	{
		memset(subdp,0,sizeof(subdp));
		subdp[0][0]=1;
		// subdp [i][j] => from the first i children of node s, number of assignments that can be made with j vaults
		int cnt=0;
		for(auto i:g[s])
		{
			if(par!=i)
			{
				for(int cur=0;cur<=x;cur++)
				for(int take=0;take<=x-cur;take++)
				{
					int tot = take+cur;
					long long val = dp[i][take][0]+dp[i][take][2];
					subdp[cnt+1][tot]=(subdp[cnt+1][tot]+val*subdp[cnt][cur])%mod;
				}
				cnt++;
			}
		}
		for(int i=0;i<=x;i++)
		dp[s][i][2]=(subdp[cnt][i]*(m-k))%mod;
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		u--,v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin>>k>>x;
	dfs(0,-1);
	long long ans=0;
	for(int i=0;i<=x;i++){
		ans+=dp[0][i][0]+dp[0][i][1]+dp[0][i][2];
		ans%=mod;
	}
	
	cout<<ans<<"\n";
	return 0;
}
