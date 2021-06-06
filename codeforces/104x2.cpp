#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,t,step;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		k--;
		if(n%2==0)
			cout<<1+(k%n)<<"\n";
		else{
			/*
			 * number of times the big cat will complete = k/n
			 * big cats final positon is k%n
			 * */
			 step = n/2;
			 step=k/step;
			 cout<<1+(k+step)%n<<"\n";
		}
	
	}
	return 0;
}
