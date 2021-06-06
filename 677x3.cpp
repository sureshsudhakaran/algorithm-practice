#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int ans,mx,n,ar[300003],flag=0;
		cin>>n;
		ar[0]=0;
		cin>>ar[1];
		mx=1;
		for(int i=2;i<=n;i++)
		{
			cin>>ar[i];
			if(ar[i]!=ar[1])
			flag++;
			if(ar[mx]<ar[i])
			mx=i;
		}
		if(flag==0)
		cout<<"-1\n";
		else
		{for(int i=1;i<=n;i++)
		{
			if(ar[i]!=ar[mx]) continue;
			if(i>1 && ar[i-1]<ar[i]){ans=i;break;}
			if(i<n && ar[i+1]<ar[i]){ans=i;break;}
		}
		cout<<ans<<"\n";}
	}
	return 0;
}
