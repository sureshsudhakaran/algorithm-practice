//Implementing KMP algorithm
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
  //Get the input
  string text,pattern;
  getline(cin,text);
  getline(cin,pattern);

  //Build the fail array for the pattern
  int m=pattern.size(),n=text.size();
  int fail[m];
  fail[0]=0; /// If you dont even match the string
  fail[1]=0;  // if you match the first element with itself you get to t
  int x=0;
  for(int i=1;i<m-1;i++)
    {
      if(pattern[i]==pattern[x])
	fail[i+1]=++x;
      else
	{
	  while(x>=1)
	    {
	      x=fail[x];
	      if(pattern[i]==pattern[x])
		{
		  fail[i+1]=++x;
		  break;
		}
	    }
	  if(x==0)
	    fail[i+1]=0;
	    
	}
    }

  int k=0,flag=0,j=0;

  while(k<n)
    {
      if(text[k]==pattern[j])
	{
	  k++;
	  j++;
	}
      else
	{
	  if(j>0)
	    j=fail[j];
	  else
	    k++;
	}
      if(j==m)
	cout<<"Found at "<<k<<endl;
    }
      
  return 0;
}
