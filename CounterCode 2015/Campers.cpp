#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k;
	cin>>n>>k;
	int a[k];
	for(int i=0;i<k;i++) {
		cin>>a[i];
	}
	sort(a,a+k);
	int prev=a[0],sum=0;
	int curr=a[0]/2-1 + a[0]%2;
	sum+=curr;
	for(int i=1;i<k;i++) {
		curr=(a[i]-prev)/2-1;
		if(curr>0)
			sum+=curr;
		prev=a[i];
		//cout<<sum<<" ";
	}
	sum += (n-prev)/2;
	cout<<sum+k<<endl;
    return 0;
}
