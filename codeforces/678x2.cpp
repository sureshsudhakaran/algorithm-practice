#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,T;
	cin>>T;
	while(T--)
	{
		cin>>t;
		for(int i=0;i<t;i++){
			for(int j=0;j<t;j++)
			{
				if((j==i)||(j==(i+1)%t))
				cout<<1<<" ";
				else
				cout<<0<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}
