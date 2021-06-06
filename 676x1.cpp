#include<bits/stdc++.h>
using namespace std;

int main()
{
	long T,i,x,a,b,a1,b1;
	cin>>T;
	while(T--)
	{
		cin>>a>>b;
		a1=a;
		b1=b;
		x=0,i=0;
		while(a||b)
		{
			if(!(((a&1)==0)&&((b&1)==0)))
				x+=(1<<i);
			a>>=1;
			b>>=1;
			i++;
		}
		cout<<(a1^x)+(b1^x)<<'\n';
	}
	return 0;
}
