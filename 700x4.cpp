#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> ar(n),cr(n+1,-1),br(n+1);
	for(int i=0;i<n;i++)
	cin>>ar[i];
	for(int i=n-1;i>=0;i--)
	{
		if(cr[ar[i]]==-1)
		{
			cr[ar[i]]=i;
			br[i]=i;
		}
		else
		{
			br[i]=cr[ar[i]];
			cr[ar[i]]=i;
		}
	}
	vector<pair<int,int>> zer,one;
	zer.push_back(make_pair(-1,-1));
	one.push_back(make_pair(-1,-1));
	for(int i=0;i<n;i++)
	{
		if(zer.back().first==ar[i]&&(one.back().first!=ar[i]))
			one.push_back(make_pair(ar[i],i));
		else if(one.back().first==ar[i]&&(zer.back().first!=ar[i]))
			zer.push_back(make_pair(ar[i],i));
		else if(br[zer.back().second]>br[one.back().second]&&(zer.back().first!=ar[i]))
			zer.push_back(make_pair(ar[i],i));
		else if(one.back().first!=ar[i])
			one.push_back(make_pair(ar[i],i));
	}
	
	for(auto i:zer)
		cout<<i.first<<"\t";
	cout<<endl;
	
	for(auto i:one)
		cout<<i.first<<"\t";
	cout<<endl;
	
	long ans=zer.size()+one.size()-2;
	cout<<ans<<"\n";
	return 0;
}
