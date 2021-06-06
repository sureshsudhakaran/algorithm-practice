#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k;
vl ar,br,ans;

void solve()
{
	cin>>n;
	int prev;
	ar.clear();
	br.clear();
	ans.clear();
	ar.resize(n);
	for(int i=0;i<n;i++)
		cin>>ar[i];
	sort(ar.begin(),ar.end());
	ans.push_back(ar[0]);
	prev=ar[0];
	for(int i=1;i<n;i++)
	{
		if(ar[i]!=prev)
		{
			prev=ar[i];
			ans.push_back(ar[i]);
		}
		else
		{
			br.push_back(ar[i]);
		}
	}
	for(auto i:ans)
		cout<<i<<" ";
	for(auto i:br)
		cout<<i<<" ";
	cout<<"\n";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}
