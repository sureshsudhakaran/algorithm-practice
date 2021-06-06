#include <bits/stdc++.h>
using namespace std;
char s[2001],t[2001];
vector<pair <int,int> > ans;
void reverse_substring(int l,int r)
{
	for (int i=0;i<(r-l+1)/2;i++)
		swap(s[l+i],s[r-i]);
}
int main()
{
	int n,k,T;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		ans.clear();
		int m=0,i=0,c=0;
		for(;c<k-1;i+=2,c++)
		{
			t[i]='(';
			t[i+1]=')';
		}
		for(int j=0;j<=(n-1-i)/2;j++)
		t[j+i]='(';
		for(int j=1+(n-1-i)/2;j<=n-1;j++)
		t[j+i]=')';
		for(i=0;i<n;i++)
		cin>>s[i];
		
		for(i=0;i<n;i++)
		{
			if(s[i]!=t[i])
			{
				int j=i+1;
				while(s[j]!=t[i]) j++;
				reverse_substring(i,j);
				m++;
				ans.push_back(make_pair(i+1,j+1));
			}
		}
		cout<<m<<"\n";
		for(auto p:ans)
		cout<<p.first<<" "<<p.second<<endl;
	}
	return 0;
}
