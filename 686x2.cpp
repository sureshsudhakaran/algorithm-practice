#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t,tmp,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		vector<int> ar(n+1,0);
		map<int,int> mp;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&tmp);
			ar[tmp]++;
			mp[tmp]=i;
		}
		ans=-1;
		for(int i=1;i<=n;i++)
			if(ar[i]==1)
			{
				ans=mp[i];
				break;
			}
		printf("%d\n",ans);
	}
	return 0;
}
