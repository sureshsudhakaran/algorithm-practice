#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,c,flag;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a.begin(),a.end());
		int c=1;
		for(int i=1;i<n;i++){
			if(a[i]==a[0])
				c++;
			else
				break;
		}
		n-=c;
		cout<<n<<"\n";
	}
	return 0;
}
