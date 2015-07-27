#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    int min = 100000000;
    for(int i=1;i<n;i++) {
        int diff = abs(a[i] - a[i-1]);
        if(diff<min)
            min = diff;
    }
    for(int i=1;i<n;i++) {
        int diff = abs(a[i] - a[i-1]);
        if(diff==min)
            cout<<a[i-1]<<" "<<a[i]<<" ";
    }
    return 0;
}