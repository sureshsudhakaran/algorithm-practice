#include<bits/stdc++.h>
using namespace std;
int dp[5001][5001];
char a[5002],b[5002];
int main()
{
	int n,m;
	a[0]='0';b[0]='0';
	scanf("%d%d",&n,&m);
	scanf("%s",a+1);
	scanf("%s",b+1);
	int mx=-1;
	//printf("\n%s\n%s\n",a,b);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=0;
			if(a[i]==b[j])
				dp[i][j]=dp[i-1][j-1]+2;
			dp[i][j]=max(dp[i][j],dp[i-1][j]-1);
			dp[i][j]=max(dp[i][j],dp[i][j-1]-1);
			if(dp[i][j]>mx)
			mx=dp[i][j];
		}
	}
	printf("%d\n",mx);
	return 0;
}
