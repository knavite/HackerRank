#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition(int *a, int l, int r) {
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
    return i+1;
}


int main() {
     int n;
	 cin>>n;
	 int a[n];
	 for(int i=0;i<n;i++) {
		cin>>a[i];
	 }
	 int start=0,end=n-1;
	 while(1) {
		
		int j = partition(a,start,end);
		if(j<n/2) {
			start=j+1;
		}
		else if(j>n/2) {
			end=j-1;
		}
		else
			break;
	 }
	 cout<<a[n/2]<<endl;
    return 0;
}
