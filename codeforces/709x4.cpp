#include<bits/stdc++.h>
using namespace std;
const int N = 300008;  // limit for array size
int n;  
long t[2 * N],b[N],dp[N],rng[N];

void build() {  
  for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1] , t[i<<1|1]);
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p] , t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  
    if (l&1) res = min(res,t[l++]);
    if (r&1) res = min(res,t[--r]);
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
  for(int i=0;i<n;i++)
	cout<<b[i];

  dp[0]=b[0];
  rng[0]=0;
  for(int i=1;i<n;i++)
  {
	  v1=b[smllest(rng[i-1],i)];
	  v2=b[i]+dp[i-1];
	  if(v1>=v2)
	  {
		  dp[i]=v1;
		  rng[i]=rng[i-1];
	  }
	  else
	  {
		  dp[i]=v2;
		  rng[i]
	  }
  }
 
	
  return 0;
}

