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
	ll ans = n-k;
	if(1){
		ll i = (k-1)/2;
		i+=1;
		ans+=k-i;
		cout<<ans<<"\n";
		if(ans)
		{
			for(int j=i;j<k;j++)
				cout<<j<<" ";
			for(int j=k+1;j<=n;j++)
				cout<<j<<" ";
			cout<<"\n";
		}
	}
}

int main()
{
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}
