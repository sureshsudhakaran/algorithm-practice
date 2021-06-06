#include <bits/stdc++.h>
using namespace std;
int tab[501][501];
int rmx[501];
int n,m,r,c,q;
void mxcnt(int i)
{
	int cnt=0,mx=0;
	for(int j=0;j<m;j++)
	{
		if(tab[i][j]==1)
			cnt++;
		else
		{
			mx=max(mx,cnt);
			cnt=0;
		}
	}
	mx=max(mx,cnt);
	rmx[i]=mx;
}
int check()
{
	int mx=0;
	for(int i=0;i<n;i++)
	mx=max(mx,rmx[i]);
	return mx;
}
int main()
{
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)
	{
		int cnt=0,mx=0;
		for(int j=0;j<m;j++)
		{
			cin>>tab[i][j];
			if(tab[i][j]==1)
				cnt++;
			else
			{
				mx=max(mx,cnt);
				cnt=0;
			}
		}
		mx=max(mx,cnt);
		rmx[i]=mx;
	}
	while(q--)
	{
		cin>>r>>c;
		r--,c--;
		tab[r][c]=(tab[r][c]==0?1:0);
		mxcnt(r);
		cout<<check()<<"\n";
	}
	return 0;
}
