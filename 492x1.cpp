#include<bits/stdc++.h>
#define MAXN 1e16
using namespace std;
int n;
long long f(int a)
{
	long long b=0;
	b+=a/100;
	a%=100;
	b+=a/20;
	a%=20;
	b+=a/10;
	a%=10;
	b+=a/5;
	a%=5;
	b+=a;
	return b;
}
int main()
{
	cin>>n;
	cout<<f(n)<<"\n";
	return 0;
}
