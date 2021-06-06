#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
using si = stack<long long>;
ll n,m,k,a,a1,b1,am,bm,cnt;
ll ar[MAXN];

void solve()
{
	cin>>n>>m;
	memset(ar,0,sizeof(ar));
	for(int i=0;i<n;i++)
	{
		cin>>a;
		ar[a%m]++;
	}
	cnt=0;
	for(int i=1;i<=m/2;i++)
	{
		if(i!=m-i && (ar[i]>0 || ar[m-i]>0)) {
			a1=ar[i];
			b1=ar[m-i];
			am =max(a1,b1);
			bm =min(a1,b1);
			if(am-bm<=1)
				cnt++;
			else
				cnt+=am-bm;
			//if(am>1)cnt++;
			//cout<<"cnt = "<<cnt<<"\ti = "<<i<<'\n';
		}
		
	}
	//cnt/=2;
	if(ar[0]>0)
		cnt++;
	if(m%2==0 && ar[m/2]>0)
		cnt++;
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
