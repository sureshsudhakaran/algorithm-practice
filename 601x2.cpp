//https://codeforces.com/contest/1255/problem/B
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int arr[2001];
	int T,n,m;
	long sum;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
		}
		if((n==2)||(m<n))
			cout<<"-1\n";
		else
		{
			cout<<sum*2<<"\n";
			for(int i=0;i<n-1;i++)
			cout<<i+1<<" "<<i+2<<"\n";
			cout<<n<<" 1\n";	
		}
	}
	return 0;
}
