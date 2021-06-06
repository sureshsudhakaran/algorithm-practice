#include<bits/stdc++.h>
#define N 300003
using namespace std;
using ll=long long;
struct node
{
	int tin,tout,index;
	vector<int> g;
};
bool operator <(const node& x, const node& y) 
{
    return x.tin < y.tin;
}
vector<node> nd;
vector<ll> t(N);
bool visited[N+1];
map<int,int> ind2sort;
int n,counter=0;
void dfs(int s)
{
	nd[s].index=s;
	nd[s].tin=++counter;
	visited[s]=true;
	for(int i:nd[s].g)
		if(!visited[i])
			dfs(i);
	nd[s].tout=counter;
}
void build()
{
	for(int i=n-1;i>0;i--)
		t[i]=t[i<<1]+t[i<<1|1];
}
void modify(int p,ll val)
{
	for(t[p+=n]+=val;p>1;p>>=1)
		t[p>>1]=t[p]+t[p^1];
}
ll query(int l,int r)
{
	ll res=0;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1) res+=t[l++];
		if(r&1) res+=t[--r];
	}
	return res;
}
void tr()
{
	for(int i=1;i<2*n+1;i++)
	cout<<t[i]<<"\t";
	cout<<"\n";
}
int main()
{
	int u,v,q,c,a,b,x;
	scanf("%d",&c);
	while(c--)
	{
		//cout<<"Test "<<c<<endl;
		scanf("%d%d",&n,&q);
		//printf("%d\t%d\n",n,q);
		nd.clear();
		nd.resize(n+1);
		for(int i=0;i<=n;i++)
		visited[i]=0;
		for(int i=0;i<=n;i++)
		nd[i].g.clear();
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d",&u,&v);
			nd[u].g.push_back(v);
			nd[v].g.push_back(u);
		}
		counter=0;
		dfs(1);
		sort(nd.begin()+1,nd.end());
		ind2sort.clear();
		for(int i=1;i<=n;i++)
			ind2sort[nd[i].index]=i;
		t.clear();
		t.assign(2*n+1,0);
		build();
		while(q--)
		{
			scanf("%d%d%d",&a,&b,&x);
			if(x==0)
			{
				a=ind2sort[a];
				b=ind2sort[b];
				if(nd[b]<nd[a])
				swap(a,b);
				int nc=nd[b].tout-nd[b].tin;
				ll ans=query(b,b+nc+1);
				printf("%lld\n",abs(ans));
			}
			else
			{
				/*if(x==2441538)
				{
					int flag=true;
					cout<<"Debug";
				}*/
				a=ind2sort[a];
				b=ind2sort[b];
				modify(a,x);  // seed +ve
				modify(b,-1*x); // pots -ve
				//~ tr();
			}
		}
	}
	return 0;
}
