#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    long long sum = 0;
    cin>>n;
    while(n--) {
        int t;
        cin>>t;
        sum+=t;
    }
    cout<<sum<<endl;
    return 0;
}
