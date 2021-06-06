#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll sm(ll n) {
	ll s=0;
	while(n) {
		s+=n%10;
		n/=10;
	}
	return s;
}
void solve() {
	ll n,s;
	cin>>n;
	s=sm(n);
	if(__gcd(n,s)>1)
		cout<<n<<"\n";
	else {
		n++;
		s=sm(n);
		if(__gcd(n,s)>1)
		cout<<n<<"\n";
		else
		cout<<n+1<<"\n";
	}
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}
