#include <bits/stdc++.h>
using namespace std;
vector<int> b;

int main()
{
	int n,a,x,y,T;
	
	cin>>T;
	while(T--)
	{
		b.clear();
		cin>>n;
		
		for(int i=0;i<n/2;i++)
		{
			cin>>x>>y;
			b.push_back(y);
			b.push_back(-1*x);
		}
		for(int i=0;i<n;i++)
		cout<<b[i]<<" ";
		cout<<endl;
	}
	return 0;
}
