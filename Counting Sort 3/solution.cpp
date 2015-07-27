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
        char str[100];
        cin>>t>>str;
        freq[t]++;        
    }
    for(int i=0;i<100;i++) {
        if(i==0)
            cout<<freq[i]<<" ";
        else {
            freq[i]+=freq[i-1];
             cout<<freq[i]<<" ";
        }
    }
    return 0;
}
