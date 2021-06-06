#include<bits/stdc++.h>
using namespace std;
const long long inf = 4e9;
vector<long long> s,c;
long long dp[3001][3];
int main()
{
	int n;
	cin>>n;
	s.resize(n);
	c.resize(n);
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
		cin>>c[i];
	/*
	 * dp[i][j] = minimum cost for selecting a[i] as the jth element
	 */
	for(int i=0;i<n;i++){
		dp[i][0]=c[i];
		for(int j=1;j<3;j++)
			dp[i][j]=4e9;
	}
	
	for(int i=0;i<n;i++) {
		for(int k=i+1;k<n;k++) {
			for(int j=1;j<3;j++)
				if(s[k]>s[i])
					dp[k][j] = min(dp[k][j],dp[i][j-1]+c[k]);
		}
	}
	
	long long ans = inf;
	for(int i=0;i<n;i++)
		ans=min(ans,dp[i][2]);
	if(ans==inf) ans=-1;
	cout<<ans<<"\n";
	return 0;
}
