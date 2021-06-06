#include <bits/stdc++.h>
using namespace std;
int pref[300005],a[300004];
int getsum(int l,int r)
{
	int k= pref[r+1]-pref[l];
	//cout<<"getsum "<< l <<" "<<r<<" = "<<k<<"\n";
	return k;
}
pair<int,int> best = make_pair(-1,-1);
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>a[i];
	pref[0]=0;
	for(int i=0;i<n;i++)
	pref[i+1]=pref[i]+(a[i]==0);
	// pref[i] contains number of 0s between 0 and i [0,i).
	
	for(int i=0;i<n;i++)
	{
		int l=i,r=n;
		while(l<r){
			int m=(l+r)/2;
			if(getsum(i,m)>k)
				r=m;
			else
				l=m+1;
		}
		best = max(best,make_pair(r-i,i));
		//cout<<i<<"\t"<<r<<"\n";
	}
	cout<<best.first<<"\n";
	for(int i=0;i<n;i++)
	{
		if(i>=best.second && i<best.second + best.first)
			cout<<"1 ";
		else
			cout<<a[i]<<" ";
	}
	return 0;
}
