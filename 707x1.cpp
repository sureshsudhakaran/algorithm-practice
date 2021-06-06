#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k;
vl ar;
int times[101],dep[101];
void solve()
{
	cin>>n;
	ar.resize(n);
	int tm[101], a[101],b[101];
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n;i++)
		cin>>tm[i];
	times[0]=tm[0]+a[0];
	dep[0]=max(b[0],times[0]+(b[0]-a[0]+1)/2);
	for(int i=1;i<n;i++)
	{
		times[i]=dep[i-1]+a[i]-b[i-1]+tm[i];
		dep[i]=max(b[i],times[i]+(b[i]-a[i]+1)/2);
	}
	
	
	
	cout<<times[n-1]<<"\n";
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	solve();
	return 0;
}

