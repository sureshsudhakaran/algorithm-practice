#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
using vl = vector<long>;
struct req
{
	int cnt;
	int day;
	vector<int> p;
};
bool cmp(req &a, req &b)
{
	return a.cnt<b.cnt;
}
ll n=0,m=0,k=0;
vl avail;
vector<req> rq;
vector<int> d;
void solve()
{
	for(int i=0;i<m;i++)
		rq[i].p.clear();
	rq.clear();
	cin>>n>>m;
	rq.resize(m);
	d.clear();
	d.resize(m);
	avail.clear();
	avail.resize(n+1);
	for(int i=1;i<=n;i++)
		avail[i]=(m+1)/2;
	for(int i=0;i<m;i++)
	{
		cin>>k;
		rq[i].cnt=k;
		rq[i].p.resize(k);
		rq[i].day=i;
		for(int j=0;j<k;j++)
			cin>>rq[i].p[j];
		//sort(rq[i].p.begin(),rq[i].p.end());
	}
	sort(rq.begin(),rq.end(),cmp);
	int uf=0;
	
	for(int i=0;i<m;i++)
	{
		int flag=0;
		for(int j=0;j<rq[i].cnt;j++)
		{
			//cout<<"rq cnt = "<<rq[i].cnt<<"\n";
			if(avail[rq[i].p[j]]>0) {
				avail[rq[i].p[j]]--;
				d[rq[i].day]=rq[i].p[j];
				flag=1;
				break;
			}
			
		}
		if(flag==0)
		{
			uf=1;
			break;
		}
	}
	if(uf==1)
		cout<<"NO\n";
	else{
		cout<<"YES\n";
		for(int i=0;i<m;i++)
			cout<<d[i]<<" ";
		cout<<"\n";
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}

