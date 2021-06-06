#include <bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n,m;
int l=0,r=1e6;	cin >> n >> m;
	vector<string> s(n);
	vector<vector<int>> arr(n,vector<int>(m));
	for(int i=0; i<n; i++) cin >> s[i];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(s[i][j]=='.') arr[i][j]=0;
			else if(i==0 || j==0) arr[i][j]=1;
			else arr[i][j]=min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1]))+1;
	vector<vector<int>> b(n,vector<int>(m));
	while(r-l>1)
		{
		int mid=(l+r) >> 1;
		int x=2*mid+1;
		bool flag=true;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(arr[i][j]>=x) b[i][j]=x;
				else b[i][j]=0;
		for(int i=n-1; i>=0; i--)
			for(int j=m-1; j>=0; j--)
				{
				if(i>0) b[i-1][j]=max(b[i-1][j],b[i][j]-1);
				if(j>0) b[i][j-1]=max(b[i][j-1],b[i][j]-1);
				if(i>0 && j>0) b[i-1][j-1]=max(b[i-1][j-1],b[i][j]-1);
				}
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				{
				if(arr[i][j]==0) continue;
				if(b[i][j]==0) flag=false;
				}
		if(flag) l=mid;
		else r=mid;
		}
	cout << l << endl;
	int x=2*l+1;
	vector<string> ans(n,string(m,'.'));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(arr[i][j]>=x) ans[i-l][j-l]='X';
	for(int i=0; i<n; i++)
		cout << ans[i] << endl;
	return 0;
}
