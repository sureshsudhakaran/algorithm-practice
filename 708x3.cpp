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
	if(n%2==1)
	{
		m = (n-1)/2;
		cout<<"1 "<<m<<" "<<m<<"\n";
	}
	else
	{
		if(n%4==0)
		cout<<n/2<<" "<<n/4<<" "<<n/4<<"\n";
		else
		cout<<"2 "<<n/2-1<<" "<<n/2-1<<"\n";
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}

