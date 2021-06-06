#include<bits/stdc++.h>
using namespace std;
bool valid[10];
int turn[10];
int h,m,T;
int hr,mn,hri,mni;
int trans(int a,int b)
{
	vector<int> v(b,0);
	int tmp=a;
	int j=0;
	while(a)
	{
		v[j]=a%10;
		j++;
		a/=10;
	}
	int tr=0;
	for(int i=0;i<v.size();i++)
		tr=(tr*10)+turn[v[i]];
	//cout<<"Transform of "<<tmp<<"= "<<tr<<"\n";
	return tr;
}
void add_time()
{
	mn++;
	if(mn==m)
	{
		mn=0;
		hr++;
	}
	if(hr==h)
		hr=0;
	//cout<<"Changed time to "<<hr<<":"<<mn<<"\n";
}
bool valid_time(int a,int b)
{
	if(trans(a,2)>=m)
		return false;
	if(trans(b,2)>=h)
		return false;
	/*while(a)
	{
		if(valid[a%10]==0)
			return false;
		a/=10;
	}
	while(b)
	{
		if(valid[b%10]==0)
			return false;
		b/=10;
	}*/
	return true;
}
void solve()
{
	while(!valid_time(hr,mn))
		add_time();
	
	
		printf("%02d:",hr);
	
	
		printf("%02d",mn);
	
	printf("\n");
}
int main()
{
	for(int i=0;i<10;i++)
	turn[i]=200;
	valid[0]=true;
	turn[0]=0;
	valid[1]=true;
	turn[1]=1;
	valid[2]=true;
	turn[2]=5;
	valid[3]=false;
	valid[4]=false;
	valid[5]=true;
	turn[5]=2;
	valid[6]=false;
	valid[7]=false;
	valid[8]=true;
	turn[8]=8;
	valid[9]=false;
	cin>>T;
	while(T--)
	{
		cin>>h>>m;
		hr=0,mn=0;
		hri=0,mni=0;
		string s;
		cin>>s;
		int i=0;
		while(s[i]!=':'){
			hr*=10;
			hr+=s[i]-'0';
			hri++;
			i++;
		}
		i++;
		while(i<s.size())
		{
			mn*=10;
			mn+=s[i]-'0';
			mni++;
			i++;
		}
		solve();
	}
	return 0;
}
