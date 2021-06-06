#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nck(ll n, ll k)
{
	ll ans=1;
	for(ll i=n;i>n-k;i--)
		ans*=i;
	for(ll i=k;i>1;i--)
		ans/=i;
	return ans;
}
int main()
{
	ll n,k;
	cin>>n>>k;
	ll ans=0;
	if(k>=2) ans+=nck(n,2);
	if(k>=3) ans+=2*nck(n,3);
	if(k>=4) ans+=9*nck(n,4); //deraning 4 elements
	cout<<1+ans<<endl;
	return 0;
}
