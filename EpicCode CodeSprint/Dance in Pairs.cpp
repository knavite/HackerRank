#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,K;
	cin>>n>>K;
	int b[n],g[n];
	for(int i=0;i<n;i++)
		cin>>b[i];
	for(int i=0;i<n;i++)
		cin>>g[i];
	sort(b,b+n);
	sort(g,g+n);
	int i=0,j=0,cnt=0;
	while(i<n && j<n) {
		if(abs(b[i]-g[j])<=K) {//cout<<b[i]<<" "<<g[j]<<endl;
			cnt++,i++,j++;
		} else if(b[i]<g[j]) 
			i++;
		else
			j++;
	}
	cout<<cnt<<endl;
    return 0;
}
