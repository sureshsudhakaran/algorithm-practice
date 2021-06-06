#include <bits/stdc++.h>
#define SIZE 1000001
using namespace std;
    
    
long long S[SIZE],n;
long long cost(long long k)
{
	long long cs=0;
	for(int i=0;i<n;i++)
	{
		cs+=min(S[i]%k,k-S[i]%k);
	}
	return cs;
}
int main()
{
	 ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	cin>>n;
	long long a,s=0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		s+=a;
		S[i]=s;
	}
	if(s==1)
		cout<<-1<<endl;
	else
	{
		int t=n;
		long long c=LONG_LONG_MAX;int p=2;
		while (p * p <= s) {
			if (s % p == 0) {
				c = min(c, cost(p));
				while (s % p == 0)
					s /= p;
			}
			++p;
		}
		if(s>1)
			c=min(c,cost(s));
		cout<<c<<endl;
	}
	return 0;
}
