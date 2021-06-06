#include<bits/stdc++.h>
using namespace std;
struct pr
{
	int i,j;
	int val;
};
bool operator<(const pr &a, const pr &b)
{
	return a.val<b.val;
}
bool operator==(const pr &a, const pr &b)
{
	return a.val==b.val && a.i==b.i && a.j==b.j;
}
int n,m,ar[101][101];
pr sm(int i,int j)
{
	pr mn;
	mn.val=INT_MAX;
	if(i>0)
	{
		if(ar[i-1][j]>mn.val)
		{
			mn.val=ar[i-1][j];
			mn.i=i-1;
			mn.j=j;
		}
	}
	if(i<n-1)
	{
		if(ar[i+1][j]>mn.val)
		{
			mn.val=ar[i+1][j];
			mn.i=i+1;
			mn.j=j;
		}
	}
	if(j>0)
	{
		if(ar[i][j-1]>mn.val)
		{
			mn.val=ar[i][j-1];
			mn.i=i;
			mn.j=j-1;
		}
	}
	if(j<m-1)
	{
		if(ar[i][j+1]>mn.val)
		{
			mn.val=ar[i][1+j];
			mn.i=i;
			mn.j=j+1;
		}
	}
	return mn;
}
vector<pr> mset;
vector<pr> cl;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		mset.clear();
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			scanf("%d",&ar[i][j]);	
			pr x;
			x.i=i;
			x.j=j;
			x.val=ar[i][j];
			if(x.val<0)
			mset.push_back(x);
		}
		
		int cnt;
		cl.clear();
		do
		{
			for(auto i:cl)
			{
				auto it=find(mset.begin(),mset.end(),i);
				mset.erase(it);
			}
			cnt=0;
			sort(mset.begin(),mset.end());
			for(pr tmp:mset)
			{
				if(tmp.val<0)
				{
					pr small = sm(tmp.i,tmp.j);
					if((small.val<0)||(small.val*(-1)>tmp.val))
					{
						cnt++;
						ar[tmp.i][tmp.j]*=-1;
						ar[small.i][small.j]*=-1;
						if(small.val<0)
						{
							auto it = find(mset.begin(),mset.end(),small);
							mset.erase(it);
						}
						cl.push_back(tmp);
					}
				}
			}
		}while(cnt>0);
		int SUM=0;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		SUM+=ar[i][j];
		printf("%d\n",SUM);
	}
	return 0;
}
