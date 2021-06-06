#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k;
vl ar;

void solve()
{
	cin>>n>>k;
	string s;
	cin>>s;
	ar.clear();
	for(long i=0;i<n;i++)
	if(s[i]=='*')
	ar.push_back(i);
	ll u=ar.size()-1;
	int cnt=1;
	while(u>0)
	{
		int ind=lower_bound(ar.begin(),ar.end(),ar[u]-k)-ar.begin();
		u=ind;
		cnt++;
	}
	cout<<cnt<<"\n";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}

