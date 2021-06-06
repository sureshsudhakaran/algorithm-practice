#include<bits/stdc++.h>
#define MAXN 50
using namespace std;
void quicksort(int *arr,int left,int right) { 
	if(left>=right)
	return;
	int pivot=left,tmp=arr[left];
	for(int i=left+1;i<=right;i++) {
		if(arr[i]<=tmp) {
			arr[pivot]=arr[i];
			arr[i]=arr[++pivot];
		}
	}
	arr[pivot]=tmp;
	quicksort(arr,left,pivot-1);
	quicksort(arr,pivot+1,right);
}
int main() {
	int a[MAXN];
	int n = 16;
	for(int i=0;i<n;i++)
	cin>>a[i];
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++)
	cout<<a[i]<<"\t";
	cout<<endl;
	return 0;
}
