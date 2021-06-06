#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		k=s.size();
		if(k>10)
			cout<<s[0]<<k-2<<s[k-1]<<"\n";
		else
			cout<<s<<"\n";
	}
	return 0;
}
