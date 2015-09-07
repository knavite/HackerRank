#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int isLeap(int year) {
    if ((year & 3) == 0 && ((year % 25) != 0 || (year & 15) == 0))
        return 1;
    else 
        return 0;
}
void addDays(int &sd,int &sm,int &sy) {
    sd+=7;
    if(isLeap(sy)) month[1] = 29;
    if(sd>month[sm-1]) {
        sd=sd%month[sm-1];
        sm++;
        if(sm>12) {
            sm=1;
            sy++;
        }
    }
    if(isLeap) month[1] = 28;
}

bool isGreaterOrEqual(int sd,int sm,int sy,int bd,int bm,int by) {
	if(sy>by)
		return true;
	if(sy==by && sm>bm)
		return true;
	if(sy==by && sm==bm && sd>=bd)
		return true;
	return false;
}

bool isGreater(int sd,int sm,int sy,int bd,int bm,int by) {
	if(sy>by)
		return true;
	if(sy==by && sm>bm)
		return true;
	if(sy==by && sm==bm && sd>bd)
		return true;
	return false;
}

int main() {
    int t;
    cin>>t;
    while(t--){
		int sd = 6,sm=4,sy=1900;
        int bd,bm,by;
        cin>>bd>>bm>>by;
        int ed,em,ey;
        cin>>ed>>em>>ey;
        int cnt = 0;
        while(1) {
            addDays(sd,sm,sy);
			if(isGreaterOrEqual(sd,sm,sy,bd,bm,by)) {
				if(sd==13) {
					cnt++;
					//cout<<sd<<" "<<sm<<" "<<sy<<endl;
				}
			}
			//cout<<sd<<" "<<sm<<" "<<sy<<endl;
            if(isGreater(sd,sm,sy,ed,em,ey)) 
                break;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
