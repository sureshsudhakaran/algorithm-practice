#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k;
vl ar;

void solve()
{
	cin>>n>>m;
	ll ans = n*(m/2);
	if(m%2==1)
	ans+=n/2;
	cout<<ans<<"\n";
}

int main()
{
	solve();
	return 0;
}

