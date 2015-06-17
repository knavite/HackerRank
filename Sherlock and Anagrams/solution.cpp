#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct data {
    int start;
    int end;
    int count;
} Data;


bool comp(char c1, char c2)
{
    return (c1) < (c2);
}

findNoOfAnagram(int lenStr,char str[],int lenTemp,char tempStr[]) {
	int freqTemp[26]={0},freqStr[26]={0};
	for(int i=0;i<lenTemp;i++) {
		freqTemp[tempStr[i]-'a']++;
		freqStr[str[i]-'a']++;
	}
	int cnt=0;
	int i = lenTemp;
	while(1)
	{
		int j=0;
		for(j = 0;j<26;j++) {
			if(freqStr[j]!=freqTemp[j])
				break;
		}
		if(j==26)
			cnt++;
		if(i==lenStr)
			break;
		freqStr[str[i-lenTemp]-'a']--;
		freqStr[str[i]-'a']++;
		i++;
	}
	return cnt-1;
	
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        char str[105];
        cin>>str;
        long long count = 0;
        int len = strlen(str);
		int sum = 0;
        for(int i=0;i<len;i++) {
			char tempStr[len+1];
            for(int j=i;j<len;j++) {
				tempStr[j-i] = str[j];
				tempStr[j-i+1] = '\0';
				sum+=findNoOfAnagram(len,str,j-i+1,tempStr);
				//cout<<tempStr<<"here"<<sum<<endl;
			}
                
        }
        cout<<sum/2<<endl;
    }
    return 0;
}
