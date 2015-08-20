#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long nc2(int n) {
	unsigned long long p=1;
	p=p*n*(n-1);
	return p;
}

int main() {
    int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		sort(arr,arr+n);
		unsigned long long sum=0;
		for(int i=0;i<n;i++) {
			int cnt=1;
			while(i<n-1 && arr[i]==arr[i+1]) {
				i++;cnt++;
			}
			if(cnt>1)
				sum+=nc2(cnt);
		}
		cout<<sum<<endl;
	}
    return 0;
}
