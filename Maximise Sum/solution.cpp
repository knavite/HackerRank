#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef unsigned long long ll;

int main() {
	int t;
	cin>>t;
	while(t--) {
		ll n,m;
		cin>>n>>m;
		set<ll> prefix;
		ll curr=0;
		ll maxVal = 0;
		for(int i=0;i<n;i++) {
			ll temp;
			cin>>temp;
			curr = (curr+temp)%m;
			if(curr>maxVal)
				maxVal=curr;
			set<ll>::iterator it= prefix.lower_bound(curr+1);
			if(it!=prefix.end()) {
				temp = m+(curr-(*it));
				if(temp>maxVal)
					maxVal=temp;
			}
			prefix.insert(curr);
			
		}
		cout<<maxVal<<endl;
	}
    return 0;
}
