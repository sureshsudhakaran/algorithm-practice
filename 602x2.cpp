#include <bits/stdc++.h>
#define SIZE 100002
using namespace std;
int main()
{
	int T;
	cin>>T;
	vector<int> ans;
	while(T--)
	{
		ans.clear();
		bool flag=false,vis[SIZE]={false};
		int mx,n,q,cur;
		cin>>n>>q;
		mx=q;
		vis[q]=true;
		cur=1;
		ans.push_back(q);
		for(int i=1;i<n;i++)
		{
			cin>>q;
			if(flag==false)
			{
				if(q==mx)
				{
					while(vis[cur]==true)
					{
						cur++;
					}
					if(cur<mx)
					{
						vis[cur]=true;
						ans.push_back(cur);
						cur++;
					}
					else
						flag=true;
				}
				else
				{
					ans.push_back(q);
					mx=q;
					vis[q]=true;
				}
			}
		}
		if(flag)
		cout<<-1<<endl;
		else
		{
			for(int i=0;i<n;i++)
			cout<<ans[i]<<" ";
			cout<<endl;
		}
	}
}
