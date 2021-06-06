#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,q,k,l,r,left,right,lrem,rrem,middle,ans;
	cin>>n>>q>>k;
	vector<int> ar(n);
	for(int i=0;i<n;i++)
		cin>>ar[i];
	while(q--)
	{
		cin>>l>>r;
		l--,r--;
		left=ar[l]-1;
		right=k-ar[r];
		middle=ar[r] -ar[l] -1 -(r-l-1);
		if(middle < 0) middle = 0;
		ans=left+right+middle*2;
		cout<<ans<<"\n";
		//printf("left=%ld\t,right=%ld\t,middle=%ld\n",left,right,middle);
	}
	return 0;
}
