#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,m;
	cin>>n>>m;
	if(m<=n)
		cout<<"1\n";
	else if(m>((n*(n+1))/2))
		cout<<"-1\n";
	else {
		int cnt=0;
		while(m>n) {
			m=m-n;
			n--;
			cnt++;
		}
		if(m!=0)
			cnt++;
		cout<<cnt<<endl;
	}
    return 0;
}
