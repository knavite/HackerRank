#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[5005][5005];
int main() {
    char str1[5005],str2[5005];
	cin>>str1;
	cin>>str2;
	int len=strlen(str1);
	
	for(int i=0;i<=len;i++) {
		dp[i][0] = dp[0][i] = 0;
	}
	for(int i=1;i<=len;i++) {
		for(int j=1;j<=len;j++) {
			if(str1[i-1]==str2[j-1]) 
				dp[i][j] = dp[i-1][j-1]+1;
			else 
				dp[i][j] = dp[i][j-1] > dp[i-1][j] ? dp[i][j-1] : dp[i-1][j];
		}
	}
	
	cout<<dp[len][len]<<endl;
    return 0;
}