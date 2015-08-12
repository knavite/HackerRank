//Does not work

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int find(int parent[],int i) {
	if(parent[i]>0) {
		i = find(parent,parent[i]);
	}
	return i;
}

void unionn(int parent[],int subsum[],int i,int j) {
	int parenti = find(parent,i);
	int parentj = find(parent,j);
	if(parenti!=parentj) {
		//cout<<parent[i]<<" "<<parent[j]<<endl;
		subsum[parentj]+=subsum[parenti];
		parent[parenti]=parentj;
	}
	
}


int main() {
    int n;
	cin>>n;
	int val[n+1];
	int sum = 0;
	int parent[n+1];
	int subsum[n+1];
	for(int i=1;i<=n;i++) {
		cin>>val[i];
		sum+=val[i];
		parent[i]=subsum[i]=-val[i];
	}
	
	for(int i=0;i<n-1;i++) {
		int a,b;
		cin>>a>>b;
		unionn(parent,subsum,a,b);
	}
	int mindiff = 1000000000;
	for(int i=1;i<=n;i++) {cout<<parent[i]<<" "<<subsum[i]<<" "<<sum<<" ";
		if(parent[i]<0)
			continue;
		int sumi = sum + subsum[i];
		int diff = abs(sumi+subsum[i]);
		cout<<subsum[i]<<" "<<sumi<<" "<<diff<<endl;
		
		if(diff<mindiff) 
			mindiff=diff;
	}
	cout<<mindiff<<endl;
    return 0;
}
