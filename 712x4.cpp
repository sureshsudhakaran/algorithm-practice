#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
ll n,m,k;
vl ar;
int grid[102][102];
void solve()
{
	cin>>n;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
	grid[i][j]=-1;
	vector<pair<int,int>> b,r;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if((i+j)%2==0)
		b.push_back(make_pair(i,j));
		else
		r.push_back(make_pair(i,j));
	}
	int a,ri=0,bi=0;
	for(int i=0;i<n*n;i++) {
		cin>>a;
		if(a==1) {
			// 2 is R
			if(ri<r.size()) {
				cout<<"2 "<<r[ri].first<<" "<<r[ri].second<<endl;
				ri++;
			}
			else {
				cout<<"3 "<<b[bi].first<<" "<<b[bi].second<<endl;
				bi++;
			}
		}
		else if(a==2) {
			// 2 is R
			if(bi<b.size()) {
				cout<<"1 "<<b[bi].first<<" "<<b[bi].second<<endl;
				bi++;
			}
			else {
				cout<<"3 "<<r[ri].first<<" "<<r[ri].second<<endl;
				ri++;
			}
		}
		else if(a==3) {
			if(ri<r.size()) {
				cout<<"2 "<<r[ri].first<<" "<<r[ri].second<<endl;
				ri++;
			}
			else {
				cout<<"1 "<<b[bi].first<<" "<<b[bi].second<<endl;
				bi++;
			}
		}
	}
}

int main()
{
	solve();
	return 0;
}
