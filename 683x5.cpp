#include<bits/stdc++.h>
using namespace std;
struct node
{
	node *child[2];
	int count;
	int depth;
	node()
	{
		child[0]=0;
		child[1]=0;
		count=0;
	}
}*root;
int sz(node *a)
{
	if(a!=0)
	return a->count;
	else
	return 0;
}
int best(node *x)
{
	if(x==0) return 0;
	if(x->depth==0)
	return sz(x);
	int rt=min(1,sz(x->child[1]));
	int bs=rt+best(x->child[0]);
	int left=min(1,sz(x->child[0]));
	bs=max(bs,left+best(x->child[1]));
	return bs;
}

void insert(int a)
{
	vector<int> v(32,0);
	int x;
	int bit=31;
	for(;bit>=0;bit--)
	{
		x=1<<bit;
		v[31-bit]=(x&a)?1:0;
	}
	node *cur=root;
	cur->count++;
	for(int i=0;i<32;i++)
	{
		if(v[i]==1)
		{
			if(cur->child[1]==0)
			{
				cur->child[1]=new node;
				cur->child[1]->depth=31-i;
			}
			cur=cur->child[1];
			cur->count++;
		}
		else
		{
			if(cur->child[0]==0)
			{
				cur->child[0]=new node;
				cur->child[0]->depth=31-i;
			}
			cur=cur->child[0];
			cur->count++;
		}
	}
}
int main()
{
	int a,n;
	root = new node;
	root->depth=
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		insert(a);
	}
	int cn=best(root);
	printf("%d\n",n-cn);
	return 0;
}
