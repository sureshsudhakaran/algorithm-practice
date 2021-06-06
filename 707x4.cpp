#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long long>;
ll lcm,n,m,k,mxn;
vl a,b;
pair<int,int> col[1000004];

ll check(ll a)
{
	ll ans=0;
	ll a1 = col[a].first;
	ll a2 = col[a].second;
	
}
void solve()
{
	cin>>n>>m>>k;
	a.resize(n+1);
	b.resize(m+1);
	lcm = n*m/__gcd(n,m);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		col[a[i]].first=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		col[b[i]].second=i;
	}
	ll mxc = 2*max(m,n);
	ll mch=0;
	mxn=m*n/__gcd(m,n);
	for(int i=0;i<=mxc;i++)
		mch+=check(i);
	
}

int main()
{
	solve();
	return 0;
}
