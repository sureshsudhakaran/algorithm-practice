#include <bits/stdc++.h>
using namespace std;
int dp[(1<<16)][17][17];
int mat[17][10003];
int cost1[17][17];
int cost2[17][17];
int main()
{
	int n,m,w;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		cin>>mat[i][j];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cost1[i][j]=1e9;
			for(int k=0;k<m;k++)
				cost1[i][j]=min(cost1[i][j],abs(mat[i][k]-mat[j][k]));
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cost2[i][j]=1e9;
			for(int k=0;k<m-1;k++)
				cost2[i][j]=min(cost2[i][j],abs(mat[i][k]-mat[j][k+1]));
		}
	}
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
		dp[(1<<i)][i][i]=1e9;  // the starting point for every mask
		// dp[mask][i][j] => [number of selected elements] [first][last]
	for(int mask=1;mask<(1<<n)-1;mask++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int nrows= __builtin_popcount(mask);
				if(nrows==1 || i!=j)
				{
					if((mask & (1<<i))&&(mask & (1<<j)))
					{
						for(int k=0;k<n;k++)
						{
							if(!(mask & (1<<k)))
							{
								int new_state = mask | (1<<k);
								int v = cost1[j][k];
								int cost = min(dp[mask][i][j],v);
								dp[new_state][i][k]=max(dp[new_state][i][k],cost);
							}
						}
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	ans=max(ans,min(dp[(1<<n)-1][i][j],cost2[i][j]));
	
	cout<<ans<<"\n";
	return 0;
}
