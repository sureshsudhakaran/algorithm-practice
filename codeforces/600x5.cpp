//https://codeforces.com/contest/1253/problem/E
#include <bits/stdc++.h>
using namespace std;
struct ant
{
	int left;
	int right;
};
int main()
{
	int ccost,nx,c,s,n,m;
	cin>>n>>m;
	vector<ant> a(n);
	vector<int> tcost(m+1);
	for(int i=0;i<n;i++)
	{
		cin>>c>>s;
		a[i].left=max(0,c-s);
		a[i].right=min(m,c+s);
	}
	tcost[m]=0;
	for(int i=m-1;i>=0;i--)
	{
		tcost[i]=m-i;
		for(int p=0;p<n;p++)
		{
			int left=a[p].left,right=a[p].right;
			if(left<=i+1 && right>=i+1)
			{
				tcost[i]=tcost[i+1];
				break;
			}
			if(i+1<=left)
			{
				ccost=left-i-1;
				nx=min(m,right+ccost);
				tcost[i]=min(tcost[i],ccost+tcost[nx]);
			}
		}
	}
	cout<<tcost[0]<<endl;
	//for(int i=0;i<m;i++)
	//cout<<tcost[i]<<endl;
	return 0;
}
