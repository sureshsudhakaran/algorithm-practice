#include<bits/stdc++.h>
using namespace std;
long long dp[8];
int conv(string s)
{
	int num=0;;
	int sz=s.size();
	for(int i=0;i<sz;i++)
		num+=(1<<(s[i]-'A'));
	return num;
}

int main()
{
	for(int i=1;i<8;i++)
	dp[i]=1e17;
	dp[0]=0;
	int c,n,v;
	string s;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>c;
		cin>>s;
		v=conv(s);
		for(int mask=0;mask<8;mask++)
			dp[v|mask]=min(dp[v|mask],dp[mask]+c);
	}
	if(dp[7]==1e17)
	cout<<"-1\n";
	else
	cout<<dp[7]<<"\n";
	return 0;
}
