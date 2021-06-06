#include<bits/stdc++.h>
#define MAXN 300002
#define MOD  1000007
using namespace std;
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k;
vl ar;
ll dp[20][MAXN]; //dp[i][j] counts how many ways there are to select i numbers with gcd j
ll cnt[MAXN];
void solve()
{
	cin>>n;
	ar.resize(n);
	for(int i=0;i<n;i++) {
		cin>>ar[i];
		cnt[ar[i]]++;
	}
	for(int i=1;i<n;i++)
		for(int j=2*i;j<n;j+=i)
			cnt[i]+=cnt[j];
}

int main()
{
	solve();
	return 0;
}
