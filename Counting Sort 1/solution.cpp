#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int freq[100]={0};
    for(int i=0;i<n;i++) {
        int t;
        cin>>t;
        freq[t]++;        
    }
    for(int i=0;i<100;i++) {
        cout<<freq[i]<<" ";
    }
    return 0;
}
