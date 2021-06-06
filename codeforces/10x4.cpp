#include<bits/stdc++.h>
using namespace std;
int lis[501]={0};
int pre[501];
int main()
{
	int last,cur,n,m,a[501],b[501];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
		pre[i]=-1;
	}
	
	for(int i=0;i<n;i++)
	{
		cur=0;
		last=-1;
		for(int j=0;j<m;j++)
		{
			if(a[i]==b[j])
			{
				if(cur+1>lis[j]) {
					lis[j]=cur+1;
					pre[j]=last;
				}
			}
			if(a[i]>b[j])
			{
				if(cur<lis[j])
				{
					cur=lis[j];
					last = j;
				}
				
			}
		}
		
	}
	int mi,mx=-1;
	
	for(int i=0;i<m;i++)
		if(lis[i]>mx)
		{
			mi=i;
			mx=lis[i];
		}
	cout<<mx<<"\n";
	vector<int> ans;
	
	/*for(int i=0;i<m;i++)
		cout<<pre[i]<<" ";
	cout<<"\n\n";
	*/
	while((mx>0)&&(mi>=0))
	{
		ans.push_back(b[mi]);
		mi=pre[mi];
		mx--;
	}
	reverse(ans.begin(),ans.end());
	for(auto i:ans)
		cout<<i<<" ";
	cout<<"\n";
	return 0;
}
