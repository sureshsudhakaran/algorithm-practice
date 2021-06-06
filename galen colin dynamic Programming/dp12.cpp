#include<bits/stdc++.h>
using namespace std;
struct cust
{ 
	int c,p,ind;
} cst[1003];
struct vals
{
	int val;
	int i;
	int j;
	int cnt;
	vals()
	{
		val=0;
		cnt=0;
	}
} dp[1003][1003]; 
struct tab
{
	int seat,ind;
} r[1003];

bool operator<(cust &a, cust &b)
{
	return a.c<b.c;
}
bool operator<(tab &a, tab &b)
{
	return a.seat<b.seat;
}
int main()
{
	int n,k;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>cst[i].c>>cst[i].p;
		cst[i].ind=i+1;
	}
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>r[i].seat;
		r[i].ind=i+1;
	}
	sort(r,r+k);
	sort(cst,cst+n);
	// dp[i][j] best price you can get with the first i customers and the first j tables
	
	//dp[0][j] = 0 ==> no customers
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(r[j-1].seat>=cst[i-1].c && dp[i][j].val<dp[i-1][j-1].val+cst[i-1].p)
			{
				dp[i][j].val=dp[i-1][j-1].val+cst[i-1].p;
				dp[i][j].cnt=dp[i-1][j-1].cnt+1;
				dp[i][j].i=i-1;
				dp[i][j].j=j-1;
			}
			if(dp[i][j-1].val>dp[i][j].val)
			{
				dp[i][j].val=dp[i][j-1].val;
				dp[i][j].cnt=dp[i][j-1].cnt;
				dp[i][j].i=i;
				dp[i][j].j=j-1;
			}
			if(dp[i-1][j].val>dp[i][j].val)
			{
				dp[i][j].val=dp[i-1][j].val;
				dp[i][j].cnt=dp[i-1][j].cnt;
				dp[i][j].i=i-1;
				dp[i][j].j=j;
			}
		}
	}
	
	cout<<dp[n][k].cnt<<" "<<dp[n][k].val<<"\n";
	
	int in,jn,i=n,j=k,cnt=dp[n][k].cnt;
	while(cnt&&i>0)
	{
		
		in=dp[i][j].i;
		jn=dp[i][j].j;
		if(in!=i&&jn!=j)
		{
			cout<<cst[i-1].ind<<" "<<r[j-1].ind<<"\n";
			cnt--;
		}
		i=in;
		j=jn;
	}
	
	return 0;
}
