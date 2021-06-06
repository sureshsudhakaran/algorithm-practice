#include<bits/stdc++.h>
using namespace std;
double log1(int a,int b)
{
	double x = log(a)/log(b);
	return x;
}
int main()
{
	int steps,a,b,t,x,y,z;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		steps=0;
		if(b==1){
			b=2;
			steps++;
		}
		
		x = (int) (log1(a,b));
		y = (int) (log1(a,b+1));
		while(x>=y+1)
		{
			b++;
			steps++;
			x = (int) (log1(a,b));
			y = (int) (log1(a,b+1));
		}
		while(a!=0)
		{
			a/=b;
			steps++;
		}
		cout<<steps<<"\n";
	}
	return 0;
}
