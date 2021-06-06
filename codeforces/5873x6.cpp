#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
void modify(vector<ll> &t,int p, ll value) {  
  for(t[p+=n]=value;p>1;p>>=1) 
	t[p>>1] = min(t[p],t[p^1]);
}

ll query(vector<ll> &t,int l, int r) {  
  ll res = LONG_LONG_MAX;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res,t[l++]);
    if (r&1) res = min(res,t[--r]);
  }
  return res;
}
int main()
{
	int k;
	string s;
	cin>>n>>k;
	cin>>s;
	vector<vector<pair<int,int>>> interval(n);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			int L = max(0,i-k);
			int R = min(n,i+k);
			interval[L].emplace_back(R,i+1);
		}
	}
	vector<long long> dp(n+1);
	dp[n]=0;
	vector<long long> T(2*n+3,LONG_LONG_MAX);
	modify(T,n,0);
	for(int i=n-1;i>=0;i--)
	{
		long long me=dp[i+1]+i+1;
		for(pair<int,int> a:interval[i])
		{
			int R=a.first;
			int cost=a.second;
			//~ for(int j=i+1;j<=R+1;j++)
			//~ {
				//~ me=min(me,cost+dp[j]);
			//~ }
			me=min(me,cost+query(T,i+1,R+2));
		}
		dp[i]=me;
		modify(T,i,me);
	}
	//~ for(int i=0;i<=n;i++)
	//~ cout<<dp[i]<<"\t";
	//~ cout<<"\n\n";
	
	//~ for(int i=0;i<=2*n+1;i++)
	//~ cout<<T[i]<<"\t";
	//~ cout<<"\n";
	cout<<dp[0]<<endl;
	return 0;
}
