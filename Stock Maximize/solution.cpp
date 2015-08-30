#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) 
			cin>>a[i];
		int max = a[n-1];
		unsigned long long sum=0;
		for(int i=n-1;i>=0;i--) {
			if(max>a[i])
				sum+=max-a[i];
			else
				max = a[i];
		}
		cout<<sum<<endl;
	}
    return 0;
}
