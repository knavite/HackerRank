#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[1000010];
char str[1000010][11];
char C[1000010][11];
int main() {
    int n;
    cin>>n;
    int freq[100]={0};
	
    for(int i=0;i<n;i++) {
        cin>>a[i]>>str[i];
        freq[a[i]]++;   
        if(i<n/2) {
            str[i][0] = '-';str[i][1] = '\0';
        }
    }
    for(int i=1;i<100;i++) {
        freq[i]+=freq[i-1];
    }
	
	for(int i=n-1;i>=0;i--) {
        strcpy(C[freq[a[i]]-1],str[i]);     
		freq[a[i]]--;
    }
	for(int i=0;i<n;i++) {
        cout<<C[i]<<" ";
    }
    return 0;
}
