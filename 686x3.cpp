#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		vector<int> ar(n+1),cnt(n+1,0);
		//map<int,int> mp;
		scanf("%d",&ar[0]);
		cnt[ar[0]]++;
		for(int i=1;i<n;i++)
		{
			scanf("%d",&ar[i]);
			if(ar[i]!=ar[i-1])
			cnt[ar[i]]++;
			//mp[ar[i]]=i;
		}
		int mnx,mn=1000000,ans=-1;
		for(int i=1;i<=n;i++)
			if((cnt[i]<mn)&&(cnt[i]>0))
			{
				mn=cnt[i];
				mnx=i;
			}
		if(mn==n)
			ans=0;

		else
		{
			ans=mn+1;
			
			if(ar[0]==mnx)
			ans--;
			if(ar[n-1]==mnx)
			ans--;
			//cout<<"mnx = "<<mnx<<"\t"<<"mn = "<<mn<<"\tans = "<<ans<<"\n";
			int cfirst = min(cnt[ar[0]],cnt[ar[n-1]]);
			if(ar[0]==ar[n-1])
				cfirst=min(cfirst,cnt[ar[0]]-1);
			//cout<<"cfirst = "<<cfirst<<"\n";
			ans=min(ans,cfirst);
		}
		printf("%d\n",ans);
	}
	return 0;
}
