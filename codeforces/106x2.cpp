#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k;
vl ar;

void solve()
{
	string s;
	cin>>s;
	int flag=0,state = 0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			if(state==0 || state==1)
				state=0;
			else if(state==2)
				state=3;
			else if(state==3){
				flag=1;
				break;
			}
		}
		else
		{
			if(state==0)
				state=1;
			else if(state==1 || state==2)
				state=2;
			else if(state==3)
				state=2;
		}
	}
	if(flag==0)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}
