#include<bits/stdc++.h>
#define SIZE 1000000007
using namespace std;
int main()
{
	int n,x,pos,high,less,mid,right,left=0;
	cin>>n>>x>>pos;
	if(pos>n || n==0){
	cout<<0<<endl;
	return 0;}
	right=n;
	less=0;
	high=0;
	while(left<right)
	{
		mid=(left+right)/2;
		if(pos==mid)
		break;
		if(pos>mid)
		{
			left=mid+1;
			less++;
		}
		else
		{
			right=mid;
			high++;
		}
	}
	if(high>n-x || less>x-1)
	{
		cout<<"0\n";
		return 0;
	}
	unsigned long long ans=1;
	for(unsigned long long i=x-less;i<=x-1;i++)
	{
		if(i>0)
		ans=ans*i;
		if(ans>SIZE)
			ans%=SIZE;
	}
	//cout<<ans<<"\n";
	for(unsigned long long i=n-x-high+1;i<=n-x;i++)
	{
		if(i>0)ans=ans*i;
		if(ans>SIZE)
			ans%=SIZE;
	}
	//out<<ans<<"\n";
	for(unsigned long long i=n-1-high-less;i>1;i--)
	{
		ans=ans*i;
		if(ans>SIZE)
			ans%=SIZE;
	}
	cout<<ans<<"\n";
	printf("high = %d , low =%d , x= %d\n",high,less,x);
	return 0;
}
