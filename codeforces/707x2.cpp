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
	int ind,a;
	ar.clear();
	ar.resize(n+1,0);
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a!=0)
		{
			ar[i+1]++;
			ind = max(0,i-a+1);
			ar[ind]--;
		}
		
	//cout<<"\n\n";
	}
	
	
	
	
	for(int i=1;i<n;i++)
		ar[i]+=ar[i-1];
	for(int i=0;i<n;i++)
		if(ar[i]<0)
			cout<<"1 ";
		else
			cout<<"0 ";
	cout<<"\n";
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	solve();
	return 0;
}
