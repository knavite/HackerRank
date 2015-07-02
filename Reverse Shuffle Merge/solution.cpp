#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    char str[10009];
	cin>>str;
	int freq1[26]={0},freq2[26]={0};
	int i=0;
	while(str[i]!='\0') {
		freq1[str[i]-'a']++;
		freq2[str[i++]-'a']++;
	}
	int len = i;
	i--;
	int min = len,prevMin=len;
	for(int ii=0;ii<len/2;ii++){
		i=min-1;
		min=-1;
		int tempFreq[26]={0};
		for(int j=0;j<26;j++) {
			tempFreq[j]=freq2[j];
		}
		while(i>=0) {
		//fprintf(stderr,"%d%c%dr ",tempFreq[str[i]-'a'],str[i],freq1[str[i]-'a']/2);
			if(freq1[str[i]-'a']/2==0) {
				i--;
				continue;
			}
			tempFreq[str[i]-'a']--;
			if(min==-1 || str[i]<str[min])
				min=i;
			if(tempFreq[str[i]-'a']<freq1[str[i]-'a']/2) {
				//fprintf(stderr,"break %d %d break",tempFreq[str[i]-'a'],freq1[str[i]-'a']/2);
				break;
			}
			
			i--;//fprintf(stderr,"%ct %d ",str[min],min);
		}
		for(int j=min;j<prevMin;j++)
			freq2[str[j]-'a']--;
		prevMin=min;
		freq1[str[min]-'a']--;freq1[str[min]-'a']--;
		//fprintf(stderr,"Selected %ch %d \n",str[min],min);
		cout<<str[min];
	}
	//cout<<str[min];
    return 0;
}
