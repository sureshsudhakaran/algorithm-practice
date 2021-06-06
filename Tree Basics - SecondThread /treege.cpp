#include<bits/stdc++.h>
#define N 300003
#define MAX 1000000000
using namespace std;
vector<double> tree;
int n;
struct node
{
	vector<int> g;
	int tin,tout,index;
}nd[N];
bool operator <(const node& x, const node& y) 
{
    return x.tin < y.tin;
}
void tr()
{
	for(int i=1;i<2*n+1;i++)
	cout<<tree[i]<<"\t";
	cout<<"\n";
}
bool visited[N];
int counter=0;
void dfs(int s)
{
	nd[s].tin = ++counter;
	nd[s].index = s;
	visited[s]=true;
	for(int i:nd[s].g)
		if(!visited[i])
			dfs(i);
	nd[s].tout=counter;
}
void build()
{
	for(int i=n-1;i>0;i--)
	tree[i]=tree[i<<1]+tree[i<<1|1];
}
void modify(int p,double val)
{
	for(tree[p+=n]=val;p>1;p>>=1)
	tree[p>>1]=tree[p]+tree[p^1];
}
double query(int l,int r)
{
	double res=1;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1) res+=tree[l++];
		if(r&1) res+=tree[--r];
	}
	return res;
}
int main()
{
	int u,v,q,t,x,y;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&u,&v);
		nd[u].g.push_back(v);
		nd[v].g.push_back(u);
	}
	dfs(1);
	sort(nd+1,nd+n+1);
	map<int,int> ind2srt;
	for(int i=1;i<=n;i++)
		ind2srt[nd[i].index]=i;
	//~ cout<<"\n\n";
	//~ for(int i=1;i<=n;i++)
	//~ {
		//~ cout<<ind2srt[i]<<"\t";
	//~ }
	//~ cout<<"\n\n";
	tree.resize(2*n+1,0.0);
	build();
	//tr();
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			modify(ind2srt[x],log(y));
			//~ tr();
		}
		else
		{
			int ind1=ind2srt[x],ind2=ind2srt[y];
			int c1=nd[ind1].tout-nd[ind1].tin;
			int c2=nd[ind2].tout-nd[ind2].tin;
			double val1 = (double) query(ind1, ind1+c1+1);
			double val2 = (double) query(ind2, ind2+c2+1);
			//cout<<"Val1 = "<<val1<<" Val2 = "<<val2<<endl;
			val1-=val2;
			if((val1)>log((double)MAX))
				printf("%ld\n",(long)MAX);
			else
				printf("%0.10f\n",exp(val1));
				
		}
	}
	return 0;
}
