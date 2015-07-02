#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    int n;
	cin>>n;
	int freq1[220]={0};
	int a;
	cin>>a;
	int start=a,mid=110;
	freq1[mid]++;
	for(int i=1;i<n;i++) {
		cin>>a;
		int index = a-start;
		freq1[mid+index]++;
	}
	cin>>n;
	int freq2[210]={0};
	cin>>a;
	int index = a-start;
	freq2[mid+index]++;
	int minIndex=index,maxIndex=index;
	for(int i=1;i<n;i++) {
		cin>>a;
		int index = a-start;
		freq2[mid+index]++;
		if(a<(start+minIndex))
			minIndex = index;
		if(a>(start+maxIndex))
			maxIndex = index;
	}
	for(int i=minIndex;i<=maxIndex;i++) {
		if(freq1[mid+i]!=freq2[mid+i]) 
			cout<<(start+i)<<" ";
	}
	cout<<endl;
    return 0;
}
