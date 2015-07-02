#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition(int *a, int l, int r,int n) {

    int i, j, p, t;

    p = a[r];
    i = l - 1;

    for(j =l; j <= r-1; j++) {
        if(a[j] <= p) {
            i++;

            t = a[j];
            a[j] = a[i];
            a[i] = t;
        }
    }

    t = a[i+1];
    a[i+1] = a[r];
    a[r] = t;
	for(int i=0;i<n;i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return i+1;
}

void quicksort(int a[],int start,int end,int n) {
	if(start<end) {
		int mid = partition(a,start,end,n);
		quicksort(a,start,mid-1,n);
		quicksort(a,mid+1,end,n);
	}
}
int main() {
    int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	quicksort(a,0,n-1,n);
	
    return 0;
}
