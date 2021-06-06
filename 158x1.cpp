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
	//ar.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>m;
		if(m>0)
		ar.push_back(m);
	}
	sort(ar.begin(),ar.end(),greater<int>());
	int cur,ind=k,ans=min((int)k,(int)ar.size());
	if(k<ar.size()){
		cur=ar[k-1];
		while(ind<ar.size() && ar[ind]==cur)
		ans++,ind++;
	}
	cout<<ans<<"\n";
}

int main()
{
	solve();
	return 0;
}

