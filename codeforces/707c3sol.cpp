#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	  cin>>arr[i];
	map<int,pair<int,int>>mp;
	int fact=0;
	for(int i=0;i<n;i++){
	    for(int j=i+1;j<n;j++){
	        if(mp.find(arr[i]+arr[j])==mp.end())
	           mp[arr[i]+arr[j]]=make_pair(i,j);
	        else { 
	              set<int> st;
	              int temp=mp.find(arr[i]+arr[j])->second.first;
	              st.insert(temp+1);
	              int temp2=mp.find(arr[i]+arr[j])->second.second;
	              st.insert(temp2+1);
	              st.insert(i+1);
	              st.insert(j+1);
	             
	              if(st.size()==4){
	                  cout<<"YES"<<endl;
	             
	                 cout<<temp+1<<" "<<temp2+1<<" "<<i+1<<" "<<j+1;
	                 fact=1;
	                 break;
	              }
	              else  mp[arr[i]+arr[j]]=make_pair(i,j);
	            
	       
	             }
    	}
    	if(fact==1)
    	  break;
	}
	if(fact==0)
	cout<<"NO"<<endl;
	return 0;
}
