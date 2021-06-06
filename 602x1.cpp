#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,t,l,r;
	int maxl,minr;
	cin>>t;
	while(t--)
	{
		cin>>n;
		maxl=0;minr=1e9+1;
		for(int i=0;i<n;i++)
		{
			cin>>l>>r;
			if(l>maxl)maxl=l;
			if(r<minr)minr=r;
		}
		cout<<max(0,maxl-minr)<<"\n";
	}
	return 0;
}
