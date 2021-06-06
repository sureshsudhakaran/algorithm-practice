#include <bits/stdc++.h>
using namespace std;
long long f[200002]={0};
long long p[200002]={0};
int main()
{
	string a,b;
	cin>>a;
	cin>>b;
	long long ans=0;
	f[0]=(b[0]=='1')?1:0;
	p[0]=(b[0]=='0')?1:0;
	for(int i=1;i<b.size();i++){
		f[i]=(b[i]=='1')?f[i-1]+1:f[i-1];
		p[i]=(b[i]=='0')?p[i-1]+1:p[i-1];
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='0')
			ans+=f[b.size()-a.size()+i]-((i>0)?f[i-1]:0);
		else
			ans+=p[b.size()-a.size()+i]-((i>0)?(p[i-1]):0);
	}
	cout<<ans<<endl;
	return 0;
}
