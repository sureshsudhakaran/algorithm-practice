#include<bits/stdc++.h>
#define MOD 998244353 
using namespace std;
long dp[1002][1002][2];
// dp[i][j][0] will store the number of chaotic merges with 0-i characters from first string and 0-j characters from the second merge and the last character taken from first or second string
// need to subtract for empty strings paired .
int add(int a,int b)
{
	a=a+b;
	if(a>=MOD)
		a-=MOD;
	else if(a<0)
		a+=MOD;
	return a;
}
int main()
{
	string x,y;
	cin>>x;
	cin>>y;
	int n=x.size(),m=y.size();
	long ans=0;
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=m;j++) {
			if(i<n) dp[i+1][j][0] = add(dp[i+1][j][0],1); // for substring starting at this position using x[i]
			if(j<m) dp[i][j+1][1] = add(dp[i][j+1][1],1); // for substring starting at this position using y[j]
			if(i>0 && i<n && x[i-1]!=x[i]) dp[i+1][j][0] = add(dp[i+1][j][0],dp[i][j][0]);
			if(j>0 && i<n && y[j-1]!=x[i]) dp[i+1][j][0] = add(dp[i+1][j][0],dp[i][j][1]);
			if(i>0 && j<m && x[i-1]!=y[j]) dp[i][j+1][1] = add(dp[i][j+1][1],dp[i][j][0]);
			if(j>0 && j<m && y[j-1]!=y[j]) dp[i][j+1][1] = add(dp[i][j+1][1],dp[i][j][1]);
			ans=add(ans,dp[i][j][0]);
			ans=add(ans,dp[i][j][1]);
		}
	}
	//cout<<"Ans = "<<ans<<"\n";
	for(int i=0;i<n;i++) {
		int len,j=i;
		while(j+1<n && x[j]!=x[j+1])
			j++;
		len=j-i+1;
		long val = (len*(len+1)/2)%MOD;
		val = val*(m+1)%MOD;
		ans=add(ans,-val);
		i=j;
	}
	//cout<<"Ans = "<<ans<<"\n";
	for(int i=0;i<m;i++) {
		int len,j=i;
		while(j+1<m && y[j]!=y[j+1])
			j++;
		len=j-i+1;
		long val = (len*(len+1)/2)%MOD;
		val = val*(n+1)%MOD;
		ans=add(ans,-val);
		i=j;
	}
	//cout<<"Ans = "<<ans<<"\n";
	cout<<ans<<"\n";
	return 0;
}
