#include<bits/stdc++.h>
using namespace std;
long dp[10000007][4]={0};
const long mod = 1000000007;
int main()
{
	long n;
	cin>>n;
	dp[0][0]=1;
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<4;j++)
		for(int k=0;k<4;k++)
		{
			if(dp[i][j]&&k!=j)
				dp[i+1][k]=(dp[i+1][k]+dp[i][j])%mod;
		}
	}
	
	cout<<dp[n][0]<<"\n";
	return 0;
}
