#include<bits/stdc++.h>
using namespace std;
long long asum[100004];
long long ssum[100004];
short awake[100004];
int a[100004];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>awake[i];
	if(awake[0]==0)
		ssum[0]=a[0];
	else
		asum[0]=a[0];
	for(int i=1;i<n;i++)
	{
		asum[i]=asum[i-1];
		ssum[i]=ssum[i-1];
		if(awake[i]==0)
			ssum[i]+=a[i];
		else
			asum[i]+=a[i];
	}
	long long ans=asum[n-1]+ssum[k-1];
	
	for(int i=1;i<n-k+1;i++)
		ans=max(ans,asum[n-1]+ssum[i+k-1]-ssum[i-1]);		//0...i-1, i....i+k-1, i+k...n-1
	cout<<ans<<"\n";
	return 0;
}
