#include<bits/stdc++.h>
using namespace std;
long M=100009;
vector<long> pm;
bool isprime(long a)
{
	bool prime=true;
	for(long i=2;i*i<=a;i++)
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
	pm.push_back(2);
	pm.push_back(3);
	for(long i=4;i<=M;i++)
	{
		if(isprime(i))
		pm.push_back(i);
	}
	printf("pr = {");
	for(auto p:pm)
	printf("%ld, ",p);
	printf("};\n");
	printf("number = %d\n",pm.size());
	return 0;
}
