#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k;
vl ar;

void solve()
{
	cin>>n;
	int a,b,c,cnt=0;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		if(a+b+c>1)
			cnt++;
	}
	cout<<cnt<<"\n";
}

int main()
{
	solve();
	return 0;
}

