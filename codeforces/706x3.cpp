#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k,x,y;
vl mr,dr;

long double calc(double a,double b)
{
	return sqrt((long double)(a*a+b*b));
}

void solve()
{
	cin>>n;
	int ml=0,dl=0;
	mr.clear();
	dr.clear();
	mr.resize(n);
	dr.resize(n);
	for(int i=0;i<2*n;i++)
	{
		cin>>x>>y;
		if(x==0) {
			mr[ml++]=abs(y);
		}
		else {
			dr[dl++]=abs(x);
		}
	}
	sort(mr.begin(),mr.end());
	sort(dr.begin(),dr.end());
	long double ans = 0.0;
	for(int i=0;i<n;i++)
		ans+=calc(mr[i],dr[i]);
	cout<<fixed;
	cout<<setprecision(12);
	cout<<ans<<"\n";
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	solve();
	return 0;
}

