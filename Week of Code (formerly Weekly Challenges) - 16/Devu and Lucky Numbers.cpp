#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;

typedef long long ll;
ll factorial[310];
ll oneArray[310];

void init() {
	factorial[0]=factorial[1] = 1;
	oneArray[1] = 1;
	for(int i=2;i<310;i++) {
		factorial[i] = (factorial[i-1] * i )%MOD;
		oneArray[i] = (oneArray[i-1] *10 +1)%MOD;
	}
}

ll inverse(ll a)
{
	ll b = MOD;
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

int main() {
	init();
	
    int x,y,z;
	cin>>x>>y>>z;
	ll sum=0;
	for(int i=0;i<=x;i++)
	{
		for(int j=0;j<=y;j++)
		{
			for(int k=0;k<=z;k++)
			{
				ll digitSum = 4*i + 5*j + 6*k;
				ll perm = factorial[i+j+k-1];
				ll rep = (((factorial[i]*factorial[j])%MOD)*factorial[k])%MOD;
				sum= (sum + (((((digitSum*perm) % MOD) * oneArray[i+j+k])% MOD) * inverse(rep)) % MOD) % MOD;
				//cout<<i<<" "<<j<<" "<<k<<digitSum<<" "<<perm<<" "<<rep<<" "<<sum<<endl;
			}
		}
	}
	cout<<sum<<endl;
    return 0;
}
