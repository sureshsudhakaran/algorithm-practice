#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k,x;
vl ar;

void solve()
{
	cin>>n>>m>>x;
	x--;
	ll nr = x%n;
	ll nc = x/n;
	cout<<1+nr*m+nc<<"\n";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}

