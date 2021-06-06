#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,T,odd,even;
	long long sum;
	cin>>T;
	while(T--) {
		odd=0,even=0;
		sum=0;
		cin>>n;
		for(int i=0;i<n;i++) {
			cin>>a;
			sum+=a;
			if(a%2==0)
				even++;
			else
				odd++;
		}
		if(sum%2==1)
			cout<<"NO\n";
		else if(((sum/2)%2==1) && (odd==0))
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}
