#include <bits/stdc++.h>
using namespace std;
const int inf = 1e8;
long dp[101][1101];
int main()
{
	int v1,v2,t,d;
	cin>>v1>>v2;
	cin>>t>>d;
	/*
	 * dp[i][j] will store the maximum distance covered in the first i seconds with current velocity j 
	 */
	
	for(int i=0;i<=t;i++)
		for(int j=0;j<=1100;j++)
			dp[i][j]=-1*inf;
	
	dp[0][v1]=0;
	
	for(int i=0;i<t-1;i++) {
		for(int j=0;j<=1000;j++) {
			for(int k=-d;k<=d;k++) {
				if(j+k>=0)
					dp[i+1][j+k]=max(dp[i+1][j+k],dp[i][j]+j);
			}
		}
	}
	
	cout<<dp[t-1][v2]+v2<<endl;
	return 0;
}
