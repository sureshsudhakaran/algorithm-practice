#include<bits/stdc++.h>
using namespace std;
struct pr
{
	long val;
	int index;
}ans;
bool operator <(pr &a,pr &b)
{
	return a.val < b.val;
}
vector<pr> ar;
vector<int> cl;
int main()
{
	int n,t;
	long long W,tmp;
	unsigned long long sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&W);
		ar.clear();
		ans.index=-1;
		sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&tmp);
			if(tmp<=W)
			{
				pr te;
				te.index=i+1;
				te.val=tmp;
				ar.push_back(te);
				if(tmp>=(W+1)/2)
				{
					ans.val=tmp;
					ans.index=i+1;
				}
				if(sum<W)
					sum+=tmp;
			}
		}
		if(ans.index!=-1)
			printf("1\n%d\n",ans.index);
		else if(sum<(W+1)/2)
			printf("-1\n");
		else
		{
			sum=0;
			cl.clear();
			sort(ar.begin(),ar.end());
			for(int i=ar.size()-1;i>=0;i--)
			{
				sum+=ar[i].val;
				cl.push_back(ar[i].index);
				if(sum>=(W+1)/2)
				break;
			}
			if(cl.size()>0){
				printf("%d\n",(int)cl.size());
				for(auto i:cl)
				printf("%d ",i);
			}
			else
				printf("-1");
			printf("\n");
		}
	}
}
