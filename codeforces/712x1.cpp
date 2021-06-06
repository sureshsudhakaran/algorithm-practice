#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k;
vl ar;

void solve()
{
	string s;
	cin>>s;
	int n=s.size(),mark=-1;
	for(int i=0;i<s.size() && mark<0;i++)
	{
		if(s[i]!='a')
			mark=i;
	}
	if(mark>=0) {
		cout<<"YES\n";
		for(int i=0;i<n-mark;i++)
			cout<<s[i];
		cout<<'a';
		for(int i=n-mark;i<n;i++)
			cout<<s[i];
		cout<<"\n";
	}
	else
		cout<<"NO\n";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}
