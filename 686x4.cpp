#include<bits/stdc++.h>
using namespace std;
long long M=100009;
vector<long long> pr;
bool isprime(long long a)
{
	bool prime=true;
	for(long long i=2;i*i<=a;i++)
	{
		if(a%i==0)
		{
			prime=false;
			break;
		}
	}
	return prime;
}
int main()
{
	int t;
	pr.push_back(2);
	pr.push_back(3);
	for(long long i=5;i<=M;i++)
	{
		if(isprime(i))
		pr.push_back(i);
	}
	long long N,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		N=n;
		vector<long long> pw(9600,0);
		long long  mxi,tcnt=0,mx=0;
		for(int i=0;pr[i]*pr[i]<=n;i++)
		{
			int cnt=0;
			while(n%pr[i]==0)
			{
				n/=pr[i];
				cnt++;
				tcnt++;
			}
			pw[i]=cnt;
			if(cnt>mx)
			{
				mx=cnt;
				mxi=pr[i];
			}
		}
		if(tcnt==0)
		{
			printf("1\n%lld\n",N);
		}
		else
		{
			vector<long long> ans;
			while(mx>1)
			{
				ans.push_back(mxi);
				N/=mxi;
				mx--;
			}
			ans.push_back(N);
			printf("%ld\n",ans.size());
			for(auto p:ans)
			printf("%lld ",p);
			printf("\n");
		}
	}
	return 0;
}
