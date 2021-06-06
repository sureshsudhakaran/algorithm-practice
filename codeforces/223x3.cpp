#include<bits/stdc++.h>
using namespace std;
struct triple
{
	int uopen;
	int uclose;
	int match;
};
int u,v,n,m,k,q,sz;
vector<triple> a;
int query(int l,int r)
{
	int nm,res=0,flag=0;
	int ruo=0,ruc=0,luo=0,luc=0;
	for(l+=sz/2,r+=sz/2;l<r;l>>=1,r>>=1)
	{
		if(l&1)	{
			res+=a[l++].match;
			int tmp = min(luo,a[l-1].uclose);
			res+=tmp;
			luo+=a[l-1].uopen-tmp;
		}
		if(r&1) {
			res+=a[--r].match;
			int tmp = min(ruc,a[r].uopen);
			res+=tmp;
			ruc+=a[r].uclose-tmp;
		}
		if(l==r) 
		{
			flag=1;
			break;
		}
	}
	nm=min(a[l].uclose,luo);
	if(flag==0){
		res+=nm;
		luo-=nm;
		luo+=a[l].uopen;
	}
	if(flag==0||1){
		nm=min(ruc,luo);
		res+=nm;
	}
	return res;
}
int main()
{
	
	string s;
	cin>>s;
	n=s.size();
	sz=1;
	while(sz<=2*n+1) sz<<=1;
	a.resize(sz);
	for(int i=sz/2+n;i<sz;i++)
		a[i].match=a[i].uopen=a[i].uclose=0;
	for(int i=0;i<n;++i)
	{
		a[i+sz/2].match=0;
		if(s[i]=='(')
		{
			a[sz/2+i].uopen=1;
			a[sz/2+i].uclose=0;
		}
		else
		{
			a[sz/2+i].uopen=0;
			a[sz/2+i].uclose=1;
		}
	}
	int nm;
	for(int i=sz/2-1;i>0;i--)
	{
		nm=min(a[i<<1].uopen,a[i<<1|1].uclose);
		a[i].match=a[i<<1].match+a[i<<1|1].match+nm;
		a[i].uopen=a[i<<1].uopen+a[i<<1|1].uopen-nm;
		a[i].uclose=a[i<<1].uclose+a[i<<1|1].uclose-nm;
	}
	cin>>q;
	while(q--)
	{
		cin>>u>>v;
		u--;
		cout<<2*query(u,v)<<"\n";
	}
	return 0;
}
