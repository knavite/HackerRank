#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		char str[100009];
		cin>>str;
		int len = strlen(str);
		
		int del=-1;
		for(int i=0;i<len/2;i++) {
			if(str[i]!=str[len-i-1]) {
					del = len-i-1;
				break;
			}
		}
		//cout<<del<<endl;
		if(del!=-1) {
			int start = 0,end = len-1,i;
			for(i=0;i<len/2;i++) {
				if(start==del) start++;
				if(end==del)end--;
				if(str[start]!=str[end]) {
					break;
				}
				start++;end--;
				
			}
			if(i==len/2)
				cout<<del<<endl;
			else
				cout<<len-del-1<<endl;
		}
		else
			cout<<"-1\n";
	}
	return 0;
}