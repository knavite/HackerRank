#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) {
            cin>>a[i];
            a[i]--;
        }
        int cnt=0;
        for(int i=0;i<n;i++) {
            if(a[i]>=0) {
                int curr=i;
                //cout<<a[i];
                do {
                    int b = curr;
                    curr=a[curr];
                    a[b] = -1;
                    if(curr<0) break;
                } while(1);
                cnt++;
            }
             /*for(int ii=0;ii<n;ii++) 
                cout<<a[ii];
                 cout<<endl;*/
        }
        cout<<cnt-1<<endl;
    }
    return 0;
}
