#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k,q;
    cin>>n>>k>>q;
    int a[n];
    for(int i=0;i<n;i++) 
        cin>>a[i];
    for(int i=0;i<q;i++) 
    {
        int t;
        cin>>t;
        k=k%n;
        t = t-k;
        if(t<0) t= t+n;
        cout<<a[t]<<endl;
    }
    return 0;
}
