#include<bits/stdc++.h>
using namespace std;
vector<int> a;
void debug(vector<pair<int,int>> x)
{
	for(auto i:x)
		cout<<"("<<i.first<<" , "<<i.second<<")\n";
	cout<<"\n\n";
}
int n,k;
bool check(int x, int cur)
{
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!cur)
		{
			ans++;
			cur ^= 1;
		}
		else
		{
			if(a[i] <= x)
			{
				ans++;
				cur ^= 1;
			}
		}
	}
	return ans >= k;
}

int main()
{
	cin>>n>>k;
	a.resize(1+n);
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	int r = *max_element(a.begin(),a.end())+1;
	int l = *min_element(a.begin(),a.end())-1;
	while(l<r)
	{
		int mid = (l+r)/2;
		if(check(mid,0)||check(mid,1))
			r=mid;
		else 
			l=mid+1;
	}
	cout<<l<<"\n";
	return 0;
}
