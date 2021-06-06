#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k1,k2,w,b;
vl ar;

void solve()
{
	cin>>n>>k1>>k2;
	cin>>w>>b;
	int tm,nw,nb;
	nw=min(k1,k2);
	tm=(max(k1,k2)-min(k1,k2))/2;
	nb=n-max(k1,k2);
	nw+=tm;
	nb+=tm;
	if(nw>=w && nb >=b)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}

