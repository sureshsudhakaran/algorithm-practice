#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k;
vl ar;

void solve()
{
	long long a,b,c,p,t;
	cin>>p>>a>>b>>c;
	t=(a-p%a)%a;
	t=min(t,(b-p%b)%b);
	t=min(t,(c-p%c)%c);
	cout<<t<<"\n";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	solve();
	cout<<sizeof(long long)<<endl;
	cout<<sizeof(int)<<endl;
	cout<<sizeof(long)<<endl;
	cout<<sizeof(float)<<endl;
	cout<<sizeof(double)<<endl;
	cout<<sizeof(long double)<<endl;
	//cout<<sizeof(double double)<<endl;
	return 0;
}

