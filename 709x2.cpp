#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k;
vl ar;
bool consistent(int m)
{
	for(int i=0;i<n;i++)
		if(ar[i]>=m)
			return false;
	for(int i=1;i<n-1;i++)
	if(2*ar[i]%m!=(ar[i+1]+ar[i-1])%m)
		return false;
	return true;
}
bool consistent()
{
	for(int i=1;i<n-1;i++)
	if(ar[i]-ar[i-1]!=ar[i+1]-ar[i])
		return false;
	return true;
}
void solve()
{
	cin>>n;
	ar.clear();
	ar.resize(n);
	cin>>ar[0];
	int inc=0,dec=0;
	for(int i=1;i<n;i++){
		cin>>ar[i];
		if(ar[i]>ar[i-1])
			inc++;
		if(ar[i]<ar[i-1])
			dec++;
	}
	if(inc && dec)
	{
		for(int i=1;i<n-1;i++)
		{
			if(ar[i]-ar[i-1]!=ar[i+1]-ar[i])
			{
				m=2*ar[i]-ar[i-1]-ar[i+1];
				if(m<0)
					m*=-1;
				break;
			}
		}
		long long d=ar[1]-ar[0];
		if(d<0)
		d+=m;
		if(consistent(m))
			cout<<m<<" "<<d<<"\n";
		else
			cout<<"-1\n";
	}
	else if(inc) {
		if(consistent())
			cout<<"0\n";
		else
			cout<<"-1\n";
	}
	else if(dec) {
		if(consistent())
			cout<<"0\n";
		else
			cout<<"-1\n";
	}
	else{
		cout<<"0\n";
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}

