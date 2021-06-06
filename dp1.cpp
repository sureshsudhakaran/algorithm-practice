#include<bits/stdc++.h>
using namespace std;
int tab[100];
int main()
{
	int n;
	scanf("%d",&n);
	if(n%2==1)
	{
		printf("0\n");
		return 0;
	}
	tab[0]=0;
	tab[2]=2;
	for(int i=4;i<=n;i+=2)
		tab[i]=2*tab[i-2];
	printf("%d\n",tab[n]);
	return 0;
}
