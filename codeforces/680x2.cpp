#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,a,b,c,d;
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c>>d;
		cout<<max(a+b,c+d)<<"\n";
	}
	return 0;
}
