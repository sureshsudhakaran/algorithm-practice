#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n<=3)
		printf("1\n");
		else
		printf("%d\n",n/2);
	}
	return 0;
}
