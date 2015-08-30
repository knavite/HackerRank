#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int a[n];
		int max = INT_MIN;
		for(int i=0;i<n;i++) {
			cin>>a[i];
			if(a[i]>max)
				max=a[i];
		}
		if(max<=0) {
			cout<<max<<" "<<max<<endl;
			continue;
		}
		max=INT_MIN;
		int max_so_far=0,nonC=0;
		for(int i=0;i<n;i++) {
			max_so_far += a[i];
			if(max_so_far < 0)
				max_so_far = 0;
			if(max_so_far  > max) 
				max = max_so_far;
			if(a[i]>0)
				nonC+=a[i];
		}
		cout<<max<<" "<<nonC<<endl;
	}
    return 0;
}
