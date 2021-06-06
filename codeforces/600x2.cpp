//https://codeforces.com/contest/1253/problem/B
#include <bits/stdc++.h>
using namespace std;
int emp[1000001]={0};
vector<int> ch;
void clr()
{
	for(auto i:ch)
	emp[i]=0;
	ch.clear();
}
int main()
{
	int n;
	bool db=false;
	int c,dcnt=0,cnt=0,step=0;
	vector<int> days;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>c;
		step++;
		db=true;
		if(c>0)
		{
			if(emp[c]!=0)
			{
				cout<<-1<<"\n";
				return 0;
			}
			else{
				emp[c]=1;
				ch.push_back(c);
				cnt++;
			}
		}
		else if(c<0)
		{
			c*=-1;
			if(emp[c]!=1)
			{
				cout<<-1<<"\n";
				return 0;
			}
			else{
				emp[c]=2;
				cnt--;
				if(cnt==0)
				{
					days.push_back(step);
					step=0;
					db=false;
					dcnt++;
					clr();
				}
			}
		}
	}
	if(cnt==0){
	cout<<dcnt<<endl;
	for(auto i:days)
	cout<<i<<" ";
	cout<<endl;
	}
	else
	cout<<-1<<"\n";
	return 0;
}
