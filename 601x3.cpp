//https://codeforces.com/contest/1255/problem/C
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N,p,q,r;
	cin>>N;
	int cnt[N+1]={0};
	bool ps[N+1]={false};
	vector<int> lst[N+1];
	map<pair <int,int>,vector <int>> mm;
	for (int t=0;t<N-2;t++)
	{
		cin>>p>>q>>r;
		cnt[p]++;
		cnt[q]++;
		cnt[r]++;
		lst[p].push_back(q);
		lst[p].push_back(r);
		lst[q].push_back(p);
		lst[q].push_back(r);
		lst[r].push_back(p);
		lst[r].push_back(q);
		mm[{p,q}].push_back(r);
		mm[{q,p}].push_back(r);
		mm[{p,r}].push_back(q);
		mm[{r,p}].push_back(q);
		mm[{q,r}].push_back(p);
		mm[{r,q}].push_back(p);
	}
	int sn,st=0;
	vector<int> ans;
	for(int i=1;i<=N;i++)
	if(cnt[i]==1)
	{
		st=i;
		break;
	}
	ans.push_back(st);
	for(auto i:lst[st])
	if(cnt[i]==2)
	{
		sn=i;
		break;
	}
	ans.push_back(sn);
	ps[st]=true;
	ps[sn]=true;
	for(int j=2;j<=N;j++)
	{
		for(auto i:mm[{st,sn}])
		{
			if(ps[i]==false)
			{
				ps[i]=true;
				ans.push_back(i);
				st=sn;
				sn=i;
				break;
			}
		}
	}
	for(auto i:ans)
	cout<<i<<" ";
	cout<<endl;
	return 0;
}
