#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ull;

int main() {
    int t;
    cin>>t;
    while(t--) {
        ull n,x,y;
        cin>>n;
        ull step = n/4;
        x=-2*step;
        y=-2*step;
        n = n%4;
        if(n!=0) {
            x=x + (1+(step)*4);
            n--;
        }
        if(n!=0) {
            y = y + (2+(step)*4);
            n--;
        }
        if(n!=0) {
            x = x - (3+(step)*4);
        }
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}
