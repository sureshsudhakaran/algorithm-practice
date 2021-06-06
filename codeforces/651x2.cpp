#include<bits/stdc++.h>
using namespace std;
vector<int> odds,evens;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,ar[2002],ev,odd=0;
		scanf("%d",&n);
		odds.clear();
		evens.clear();
		for(int i=0;i<2*n;i++){
			scanf("%d",&ar[i]);
			if(ar[i]%2==1){
				odd++;
				odds.push_back(i);
			}
			else
				evens.push_back(i);
		}
		ev=n-odd;
		//~ for(auto i:odds)
		//~ cout<<i<<"\t";
		//~ cout<<"\n";
		
		//~ for(auto i:evens)
		//~ cout<<i<<"\t";
		//~ cout<<"\n";
		
		
		int flag=0,start=odd%2,steps=0;
		for(int i=start;(i+1<odds.size())&&(steps<n-1);i+=2,steps++)
			printf("%d %d\n",odds[i]+1,odds[i+1]+1);

		for(int i=0;steps<n-1;steps++,i+=2)
			printf("%d %d\n",evens[i]+1,evens[i+1]+1);

	}
	return 0;
}
