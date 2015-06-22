#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,p,x;
	cin>>n>>p>>x;
	long long max=-1;
	int maxI;
	for(int i=0;i<n;i++) {
		long long a;
		cin>>a;
		if(p*a>max) {
			max=p*a;
			maxI = i;
		}
		p-=x;
	}
	cout<<maxI+1<<endl;
    return 0;
}
