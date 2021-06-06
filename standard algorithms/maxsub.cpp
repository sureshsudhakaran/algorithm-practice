

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define FOR(i,a,n) for(long i=a;i<n;i++)
#define DFOR(i,a,n) for(long i=a;i>=n;i--)
#define pb(u) push_back(u)
#define SIZE 100002

using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;



int main()
{
  int t;
  scanf("%d",&t);
  while(t--){
  int n,mx;
  
  scanf("%d",&n);
vi a(n),m(n);
  FOR(i,0,n)
    scanf("%d",&a[i]);
  fill(m.begin(),m.end(),INT_MIN);

  mx=m[0]=a[0];
  FOR(i,1,n)
    {
      m[i]=max(m[i-1]+a[i],a[i]);
      if(mx<m[i])
	mx=m[i];
    }
  printf("%d\n",mx);
  }
  return 0;
}
