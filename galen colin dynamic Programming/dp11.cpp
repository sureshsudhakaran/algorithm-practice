#include<bits/stdc++.h>
using namespace std;
long long dp[2001][2001];
const long long mod = 1000000007;
//dp[i][j] represents number of sequences of length i that end with number j
int main()
{
	int n,k;
	cin>>n>>k;
	
	dp[0][1]=1;
	for(int i=0;i<k;i++)
		for(int j=1;j<=n;j++)
			for(int u=j;u<=n;u+=j)
				dp[i+1][u]=(dp[i+1][u]+dp[i][j])%mod;
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans+dp[k][i])%mod;
	cout<<ans<<"\n";
	return 0;
}
