#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==1)
		printf("0\n");
		else if(n==2)
		printf("1\n");
		else if(n<=4)
		printf("2\n");
		else if(n%2==1)
		printf("3\n");
		else printf("2\n");
	}
	
	
	return 0;
}
