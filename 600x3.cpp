//https://codeforces.com/contest/1253/problem/C
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	long long val,ans[200001];
	scanf("%d %d",&n,&m);
	vector<int> ar(n);
	for(int i=0;i<n;i++)
	scanf("%d",&ar[i]);
	sort(ar.begin(),ar.end());
	val=0;
	for(int k=1;k<=n;k++)
	{
		val+=ar[k-1];
		ans[k-1] = val;
		if(k>m)
		ans[k-1]+=ans[k-1-m];
		printf("%lld ",ans[k-1]);
	}
	return 0;
}
