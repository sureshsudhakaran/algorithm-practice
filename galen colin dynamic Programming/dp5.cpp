#include<bits/stdc++.h>
using namespace std;
long long dp[2002][1002],a[1002],b[2002];
const long long INF = LONG_LONG_MAX/2;
int main()
{
	int n,k,p;
	cin>>n>>k>>p;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<k;i++)
		cin>>b[i];
	sort(a,a+n);
	sort(b,b+k);
	for(int i=0;i<=k;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=INF;
	dp[0][0]=0;	// dp (pos, last)
	for(int i=0;i<=k;i++)
		for(int j=0;j<=n;j++)
		{
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
			if(j<n)
			dp[i+1][j+1]=min(dp[i+1][j+1],max(dp[i][j],abs(b[i]-a[j])+abs(b[i]-p)));
		}
	long long mn=INF;
	for(int i=0;i<=k;i++)
		mn=min(mn,dp[i][n]);
	cout<<mn<<endl;
	return 0;
}
