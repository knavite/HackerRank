#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
	cin>>n;
	int a[n],choco[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if(i!=0) {
			if(a[i]>a[i-1]) 
				choco[i] = choco[i-1]+1;
			else
				choco[i] = 1;
		}
		else
			choco[i]=1;
	}
	int sum=choco[n-1];
	//cout<<sum<<" ";
	for(int i=n-1;i>0;i--) {
		if(a[i-1]>a[i])
			choco[i-1] = max(choco[i-1],choco[i]+1);
		sum+=choco[i-1];
		//cout<<a[i-1]<<" ";
	}
	cout<<sum<<endl;
    return 0;
}
