#include <bits/stdc++.h>
#define SIZE 250001
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		int tab[501][501];
		int row[m][n],col[n][m];
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		cin>>row[j][i];
		for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		cin>>col[j][i];
		
		
		/*cout<<"\n";
		cout<<"\n\n\n";
		
		for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
		cout<<row[i][j]<<" ";
		cout<<"\n";}
		cout<<"\n\n";
		for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		cout<<col[i][j]<<" ";
		cout<<"\n";}
	
		cout<<"\n\n";*/
		
		int X=min(m,n);
		for(int k=0;k<X;k++)
		{
			for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				//cout<<"Comparing "<<row[k][i]<<" with "<<col[k][j]<<"\n";
				if(row[k][i]==col[k][j])
				{
					//cout<<"Matched "<<k<<" to "<<row[k][i]<<"\n";
			
					for(int i1=k;i1<m;i1++)
					tab[k][i1]=row[i1][i];
					for(int i1=k;i1<n;i1++)
					tab[i1][k]=col[i1][j];
				}
				
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
			cout<<tab[i][j]<<" ";
			cout<<"\n";
		}

	}
	return 0;
}
