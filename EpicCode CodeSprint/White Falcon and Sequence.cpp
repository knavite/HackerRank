#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
	cin>>n;
	long long f[n],b[n];
	for(int i=0;i<n;i++) {
		cin>>f[i];
		b[n-1-i]=f[i];
	}
	long long max = 0;
	for(int i=0;i<n;i++) {
		long long sum = 0;
		for(int j=0;j<(n-i)/2;j++) {
			sum+=f[i+j]*b[j];
		}
		if(sum>max)
			max=sum;
	}
	for(int i=0;i<n;i++) {
		long long sum = 0;
		for(int j=0;j<(n-i)/2;j++) {
			sum+=b[i+j]*f[j];
		}
		if(sum>max)
			max=sum;
	}
	cout<<max<<endl;
    return 0;
}
