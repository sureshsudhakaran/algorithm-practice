#include <bits/stdc++.h>
using namespace std;
int a[200001];
int x[5000003],y[5000003];
int main()
{
	//solve();
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	
	int flag=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(!x[a[i]+a[j]])
			{
				x[a[i]+a[j]]=i;
				y[a[i]+a[j]]=j;
			}
			else{
				if(x[a[i]+a[j]]!=i && x[a[i]+a[j]]!=j && y[a[i]+a[j]]!=i && y[a[i]+a[j]]!=j) {
					printf("YES\n");
					printf("%d %d %d %d",x[a[i]+a[j]],y[a[i]+a[j]],i,j);
					flag=1;
					return 0;
				}
			}
		}
		if(flag==1)
		break;
	}
	if(!flag)
		printf("NO\n");
	return 0;
}
