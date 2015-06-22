#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
	cin>>n;	
	char str[n+1];
	cin>>str;
	long long freq[26]={0};
	for(int i=0;i<n;i++) {
		freq[str[i]-'a']++;
	}
	long long sum = 0;
	for(int i=0;i<26;i++) {
		sum += (freq[i]*(freq[i]+1))/2;
	}
	cout<<sum<<endl;
    return 0;
}
