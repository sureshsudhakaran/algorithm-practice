#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k;
vl ar;

bool validate(string s1,string s2) {
	int cnt=0;
	int n=s1.size();
	for(int i=0;i<n;i++) {
		if(s1[i]=='(')
			cnt++;
		else
			cnt--;
		if(cnt<0)
			return false;
	}
	if(cnt!=0)
	return false;
	for(int i=0;i<n;i++) {
		if(s2[i]=='(')
			cnt++;
		else
			cnt--;
		if(cnt<0)
			return false;
	}
	if(cnt!=0)
	return false;
	return true;
}

void solve()
{
	scanf("%lld",&n);
	char s[MAXN];
	scanf("%s",s);
	int oc=0,zc=0,zct=0,oct=0;
	for(int i=0;i<n;i++) {
		if(s[i]=='0')
		zc++;
		else oc++;
	}
	string ans1,ans2;
	for(int i=0;i<n;i++) {
		if(s[i]=='1') {
			if(oct<oc/2) {
				ans1+="(";
				ans2+="(";
			}
			else {
				ans1+=")";
				ans2+=")";
			}
			oct++;
		}
		else {
			if(zct%2==0) {
				ans1+=")";
				ans2+="(";
			}
			else {
				ans1+="(";
				ans2+=")";
			}
			zct++;
		}
	}
	if(validate(ans1,ans2))
	{
		printf("YES\n%s\n%s\n",ans1.c_str(),ans2.c_str());
	}
	else
		printf("NO\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	solve();
	return 0;
}
