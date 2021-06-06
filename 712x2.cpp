#include<bits/stdc++.h>
#define MAXN 300005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k;
vl ar;

void solve()
{
	scanf("%lld",&n);

	char a[MAXN],b[MAXN];
	scanf("%s",a);
	scanf("%s",b);
	vector<bool> valid(n,false);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]=='0')
		cnt++;
		else
		cnt--;
		if(cnt==0)
		valid[i]=true;
	}
	bool flip=false,flag=false;
	for(int i=n-1;i>=0;i--) {
		if(a[i]!=b[i] && !flip) {
			if(!valid[i]) {
				flag=1;
				break;
			}
			else 
				flip=!flip;
		}
		else if(a[i]==b[i] && flip) {
			if(!valid[i]) {
				flag=1;
				break;
			}
			else
				flip=!flip;
		}
	}
	if(flag)
		printf("NO\n");
	else
		printf("YES\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	solve();
	return 0;
}
