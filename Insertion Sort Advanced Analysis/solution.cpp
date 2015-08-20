#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long merge(int a[],int l,int mid,int r) {
	int temp[r-l+1];
	int i=l,j=mid+1,k=0;
	unsigned long long invCount=0;
	while(i<=mid && j<=r) {
		if(a[i]<=a[j]) 
			temp[k++] = a[i++];
		else {
			temp[k++] = a[j++];
			invCount+=mid-i+1;
		}
	}
	while(i<=mid)
		temp[k++] = a[i++];
	while(j<=r)
		temp[k++] = a[j++];
	for(int i=l;i<=r;i++)
		a[i]=temp[i-l];
	return invCount;
}
unsigned long long mergesort(int a[],int l,int r) {
	int mid = (l+r)/2;
	//fprintf(stderr,"%d %d\n",l,r);
	if(l<r) {
		unsigned long long left=mergesort(a,l,mid);
		unsigned long long right=mergesort(a,mid+1,r);
		return merge(a,l,mid,r)+left+right;
	}
	return 0;
}

int main() {
    int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) {
			cin>>a[i];
		}
		unsigned long long res=mergesort(a,0,n-1);
		/*for(int i=0;i<n;i++) {
			cout<<a[i]<<" ";
		}*/
		cout<<res<<endl;
	}
    return 0;
}
