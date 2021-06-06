#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<long long,int> PLI;
typedef pair<long long,long long> PLL;
const ll mod=1000000007;
//mt19937_64 mrand(random_device{}()); 
//int rnd(int x) { return mrand() % x;}
//__builtin_popcount(n)
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int n,m;
ll k;
int a[500066],b[500066];
int pos[1000066];
ll f[500066];
ll T;

ll exgcd(ll a,ll b,ll&x,ll&y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	ll g=exgcd(b,a%b,x,y);
	ll tmp=x;
	x=y;
	y=tmp-a/b*y;
	return g;
}

ll cal(ll w)
{
	ll same=0;
	for(int i=0;i<m;i++)
	{
		if(f[i]>=0&&f[i]<=w)
		{
			ll tmp;
			if(!f[i])tmp=w;
			else tmp=w-1-f[i]+1;
			same+=tmp/T+(tmp%T!=0);
		}
	}
	return same;
}

int main(){
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		pos[a[i]]=i+1;
	}
	int G=__gcd(n,m);
	T=1ll*n/G*m;
	for(int i=0;i<m;i++){
		scanf("%d",&b[i]);
		if(pos[b[i]]&&(i+1-pos[b[i]])%G==0){
			ll x,y;
			exgcd(n/G,m/G,x,y);
			ll tmp=x*n*((i+1-pos[b[i]])/G)+pos[b[i]]-1;
			tmp=(tmp%T+T)%T;
			f[i]=tmp;
				
		}
		else f[i]=-1;
	}

	// printf("%lld %d__\n",f[0],pos[1]);
	// printf("%lld\n",cal(6));
	// return 0;

	ll l=0,r=1e18;
	k--;
	while(l<r)
	{
		ll mid=(l+r+1)>>1;
		if(mid-cal(mid)>k)r=mid-1;
		else l=mid;
	}
	printf("%lld\n",l+1);
	return 0;
}

/*


4 2 4
4 2 3 1
2 1


1 2 3
1
1 2


*/
