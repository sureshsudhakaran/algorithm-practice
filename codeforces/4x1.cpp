#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k;
vl ar;

void solve()
{
	cin>>n;
	if(n%2==0 && n>2)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}

int main()
{
	solve();
	return 0;
}

