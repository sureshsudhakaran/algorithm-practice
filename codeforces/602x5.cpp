//https://codeforces.com/contest/1262/problem/E
#include<bits/stdc++.h>
#define SIZE 1000006
using namespace std;
int n,m;
vector<bool> val[SIZE];
vector<int> pre[SIZE],presq[SIZE],res[SIZE];
int main()
{
ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<=n;++i)
	for(int j=0;j<=m;++j)
		val[i].push_back(0),pre[i].push_back(0),presq[i].push_back(0),res[i].push_back(0);
	
	char c;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	{
		cin>>c;
		pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
		if(c=='X')
		{
			res[i][j]=1;
			++pre[i][j];
			val[i][j]=true;
		}
	}
	int mid,z,tgt,flag,le=1,ans=0,re=min(n,m)/2;
	while(le<=re)
	{
		mid=(le+re)/2;
		z=2*mid+1;
		tgt=z*z;
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			presq[i][j]=0;
		for(int i=z;i<=n;++i)
		for(int j=z;j<=m;++j)
		{
			if(pre[i][j]-pre[i-z][j]-pre[i][j-z]+pre[i-z][j-z]==tgt)
				presq[i-mid][j-mid]=1;
		}
		
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			presq[i][j]+=presq[i-1][j]+presq[i][j-1]-presq[i-1][j-1];
		
		flag=1;
		int x1,y1,x2,y2;
		for(int i=1;i<=n;++i){
			if(!flag) break;
			for(int j=1;j<=m;++j)
			if(val[i][j])
			{
				x1=max(0,i-mid-1),x2=min(n,i+mid);
				y1=max(0,j-mid-1),y2=min(m,j+mid);
				if(presq[x2][y2]-presq[x2][y1]-presq[x1][y2]+presq[x1][y1]==0)
					flag=0;
			}
		}
		if(flag)
		{
			for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				res[i][j]=presq[i][j]-presq[i-1][j]-presq[i][j-1]+presq[i-1][j-1];
			ans=mid;
			le=mid+1;
		}
		else
			re=mid-1;
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(res[i][j])
				cout<<"X";
			else
				cout<<".";
		}
		cout<<"\n";
	}
	
	for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++)
	cout<<res[i][j]<<"\t";
	cout<<endl;}
	return 0;
}
