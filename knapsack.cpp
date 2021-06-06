#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<n;i++)
#define WMAX 100
#define NMAX 100
using namespace std;

struct item
{
  int index;
  int weight;
  int value;
  bool operator<(item a) {  return a.value>value; }
};

int main()
{
  int n,wt,val;
  vector<item> ls;
  cin>>n>>wt;
  FOR(i,n)
  {
    cin>>wt>>val;
    item k;
    k.index=i;
    k.weight=wt;
    k.value=val;
    ls.insert(ls.end(),k);
  }
  
  int tab[NMAX][WMAX]={0};
  FOR(i,wt+1)
    {
      if(i<ls[0].weight)
	tab[0][i]=0;
      else
	tab[0][i]=ls[0].value;
    }
  cout<<"ls[0].val = "<<ls[0].value<<endl;
  FOR(i,wt+1)
    cout<<tab[0][i]<<"\t";
  cout<<endl;
  
  for(int i=1;i<n;i++)
    for(int j=0;j<=wt;j++)
	{
	  if(ls[i].weight>j)
	    tab[i][j]=tab[i-1][j];
	  else
	    tab[i][j]=max(tab[i-1][j],tab[i-1][j-ls[i].weight]+ls[i].value);  
	}

  
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<=wt;j++)
	cout<<tab[i][j]<<"\t";
      cout<<endl;
    }
      
  
  return 0;
}
