#include<bits/stdc++.h>
using namespace std;
char s[104],z[104],o[104];
int main()
{
	int ans,l,r,n,q,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		scanf("%s",s);
		z[0]=s[0]=='0'?1:0;
		for(int i=1;i<n;i++)
		z[i]=z[i-1]+(s[i]=='0'?1:0);
		for(int i=0;i<n;i++)
		o[i]=i+1-z[i];
		while(q--)
		{
			scanf("%d%d",&l,&r);
			l--;r--;
			ans=0;
			if(r-l<1)
			ans=0;
			else
			{
				if(l>0)
				{
					if(s[l]=='0'&&z[l-1]>0) ans=1;
					else if(s[l]=='1'&& o[l-1]>0) ans=1;
				}
				if(r<n-1)
				{
					if(s[r]=='0'&&(z[n-1]-z[r]>0)) ans=1;
					else if(s[r]=='1'&&(o[n-1]-o[r]>0)) ans=1;
				}
			}
			if(ans==0)
			printf("NO\n");
			else
			printf("YES\n");
		}
	}
	
	return 0;
}

