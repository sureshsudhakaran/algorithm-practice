#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
		long long bt,btl,A,B,n,dmg=0,dead=0;
		cin>>A>>B>>n;
		vector<long long> atk(n),hp(n);
		for(int i=0;i<n;i++)
			cin>>atk[i];
		for(int i=0;i<n;i++){
			cin>>hp[i];
			bt=(hp[i]+A-1)/A;
			dmg+=bt*atk[i];
		}
		long long mx = *max_element(atk.begin(),atk.end());
		if(dmg-mx>=B)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}
