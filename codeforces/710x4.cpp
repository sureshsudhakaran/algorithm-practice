#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k;
vl ar;
stack<int> st;
void solve()
{
	while(!st.empty())
	st.pop();
	cin>>n;
	ar.clear();
	ar.resize(n);
	for(int i=0;i<n;i++)
	cin>>ar[i];
	for(int i=0;i<n;i++)
	{
		if(st.empty())
		{
			st.push(ar[i]);
		}
		else if(st.top()==ar[i])
			st.push(ar[i]);
		else
			st.pop();
	}
	ll ans=0;
	if(st.empty())
		ans=0;
	else {
		int p=st.top();
		int cnt=0;
		for(int i=0;i<n;i++)
		if(ar[i]==p)
		cnt++;
		ans=max(2*cnt-n,(long long)0);
	}
	if(n%2==1)
	ans=max((long long)1,ans);
	cout<<ans<<"\n";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}

