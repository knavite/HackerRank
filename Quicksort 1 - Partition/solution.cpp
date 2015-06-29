#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void partition(vector <int>  ar) {
    int pivot = 0;
    int i=1,j=ar.size()-1;
    while(i<j) {
        while(ar[i]<ar[pivot]) i++;
        while(ar[j]>ar[pivot]) j--;
        if(i<j) {
            int t=ar[i];
            ar[i]=ar[j];
            ar[j]=t;
        }
    }
    int t=ar[j];
    ar[j]=ar[pivot];
    ar[pivot]=t;
    for(int i=0;i<ar.size();i++)
        cout<<ar[i]<<" ";
}
int main(void) {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp); 
}

partition(_ar);
   
   return 0;
}
