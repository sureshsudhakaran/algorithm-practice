#include<bits/stdc++.h>
#define MAXN 1e16
using namespace std;
using ll = long long;
using vl = vector<long long>;
ll n,m,k;
vl dp,mn,c,sm;

void solve()
{
	cin>>n;
	dp.clear();
	mn.clear();
	sm.clear();
	c.clear();
	c.resize(n);
	dp.resize(n);
	mn.resize(n);
	sm.resize(n);
	for(int i=0;i<n;i++) {
		cin>>c[i];
	}
	mn[0] = sm[0] = c[0];
	mn[1] = sm[1] = c[1];
	for(int i=2;i<n;i+=2) {
		mn[i] = min(c[i],mn[i-2]);
		sm[i] = c[i] + sm[i-2];
	}
	for(int i=3;i<n;i+=2) {
		mn[i] = min(c[i],mn[i-2]);
		sm[i] = c[i] + sm[i-2];
	}
	dp[0]=n*c[0];
	dp[1]=n*c[1];
	for(int i=2;i<n;i+=2)
	{
		dp[i] = (n-1-i/2)*mn[i] + sm[i];
	}
	for(int i=3;i<n;i+=2)
	{
		dp[i] = (n-1-i/2)*mn[i] + sm[i];
	}
	long long ans=MAXN;
	for(int i=1;i<n;i++)
		ans=min(ans,dp[i]+dp[i-1]);
	cout<<ans<<"\n";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}

