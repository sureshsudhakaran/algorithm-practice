#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int a,b,c,d,T;
	cin>>T;
	while(T--)
	{
		cin>>a>>b;
		d=a-b;
		c=0;
		if(d<0) d*=-1;
		c=d/5;
		d=d%5;
		if(d==1||d==2)
		c++;
		else if(d==3||d==4)
		c+=2;
		cout<<c<<endl;
	}
	return 0;
}
