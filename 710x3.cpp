#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k;
vl ar;
string a,b,q;
int dp[21][21][21][21];
int check(int n1,int n2, int m1,int m2)
{
	
	if(n1>n2 || m1 > m2)
	{
			if(n1>n2 && m1>m2)
			return 0;
			return 200;
	}
	if(dp[n1][n2][m1][m2]!=-1)
		return dp[n1][n2][m1][m2];
	
	string s1 = a.substr(n1,n2-n1+1);
	string s2 = b.substr(m1,m2-m1+1);
	int a;
	if(s1==s2){
		dp[n1][n2][m1][m2]=0;
		//cout<<s1<<"\n";
		return 0;
	}
	else {
		a = 1 + check(n1+1,n2,m1,m2);
		a=min(a,1+check(n1,n2-1,m1,m2));
		a=min(a,1+check(n1,n2,m1+1,m2));
		a=min(a,1+check(n1,n2,m1,m2-1));
	}
	dp[n1][n2][m1][m2]=a;
	return a;
}
void solve()
{
	a.clear();
	b.clear();
	for(int i=0;i<21;i++)
	for(int j=0;j<21;j++)
	for(int k=0;k<21;k++)
	for(int u=0;u<21;u++)
	dp[i][j][k][u]=-1;
	getline(cin,a);
	getline(cin,b);
	n=a.size(),m=b.size();
	int ans = check(0,n-1,0,m-1);
	if(ans>n+m)
		ans=n+m;
	cout<<ans<<"\n";
	//cout<<q<<"\n";
}

int main()
{
	int t;
	cin>>t;
	char c=getchar();
	while(t--)
	solve();
	return 0;
}

