#include <bits/stdc++.h>
using namespace std;
char conv(int k)
{
	if(k<26)
	return 65+k;
	if(k<52)
	return 97+k-26;
	return k-52+48;
}
int main()
{
	//cout<<conv(0)<<"\t"<<conv(26)<<"\t"<<conv(52)<<"\t"<<conv(61)<<endl;
	//return 0;
	int T,r,c,rice,k,ch,shr;
	char a[101][101],ans[101][101];
	cin>>T;
	while(T--)
	{
		ch=0,rice=0;
		cin>>r>>c>>k;
		for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='R')
			rice++;
		}
		shr=rice/k;
		int rem=rice%k;
		int cur=0;
		if(rem>0)
		{
			rem--;
			cur=-1;
		}
		char c1=conv(ch);
		for(int i=0;i<r;i++)
		{
			if(i%2==0)
			{
				for(int j=0;j<c;j++)
				{
					ans[i][j]=c1;
					if(a[i][j]=='R')
					{
						cur++;
						if((cur==shr)&&(ch!=k-1))
						{
							ch++;
							c1=conv(ch);
							if(rem>0)
							{
								rem--;
								cur=-1;
							}
							else
							cur=0;
						}
					}
					
				}
			}
			else
			{
				for(int j=c-1;j>=0;j--)
				{
					ans[i][j]=c1;
					if(a[i][j]=='R')
					{
						cur++;
						if((cur==shr)&&(ch!=k-1))
						{
							ch++;
							c1=conv(ch);
							if(rem>0)
							{
								rem--;
								cur=-1;
							}
							else cur=0;
						}
					}
					
				}
			}
		}
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			cout<<ans[i][j];
			cout<<endl;
		}
	}
	return 0;
}
