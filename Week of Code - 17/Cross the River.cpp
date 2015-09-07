#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <climits>
using namespace std;

struct compare {
	bool operator()(const vector<int> a, const vector<int> b) 
	{
		return a[0]<b[0];
	}
	bool operator()(const vector<int> a, const int b) 
	{
		return a[0]<b;
	}
	bool operator()(const int a, const int b) 
	{
		return a<b;
	}
	bool operator()(const int a, const vector<int> b) 
	{
		return a<b[0];
	}
};

set<vector<int>,compare>  a[10000000];
int main() {
	int n,h,dh,dw;
	cin>>n>>h>>dh>>dw;
	set<int> yset;
	for(int i = 0;i<n;i++) {
		int y,x,z;
		cin>>y>>x>>z;
		yset.insert(y);
		vector<int> v;
		v.push_back(x);
		v.push_back(z);
		if(y<=dh)
			v.push_back(z);
		else
			v.push_back(INT_MIN);
		a[y].insert(v);
	}
	set<int>::iterator it;
	int maxVal = INT_MIN;
	for (it = yset.begin(); it !=yset.end(); ++it)
	{
		int y = *it; 
		//cout<<"Testing "<<y<<endl;
		set<vector<int>,compare>::iterator it2;
		set<int>::iterator it3;
		for (it2 = a[y].begin(); it2 !=a[y].end(); ++it2) {
			vector<int> x = *it2;
			it3 = it;it3++;
			//cout<<"Testing x"<<x[0]<<endl;
			for(;it3!=yset.end();++it3) {
				int newY = *it3;
				//cout<<"Testing newY"<<newY<<endl;
				if((newY-y)<=dh) {
					int low = x[0]-dw;
					int high = x[0]+dw;
					vector<int> temp;
					temp.push_back(low);
					set<vector<int>,compare>::iterator lowIt = a[newY].lower_bound(temp);
					temp.clear();
					temp.push_back(high);
					set<vector<int>,compare>::iterator highIt = a[newY].upper_bound(temp),it4;
					//cout<<"bound "<<(*lowIt)[0]<<" "<<endl;
					for(it4 = lowIt;it4!=highIt && it4!=a[newY].end();++it4) {
						
						vector<int> v = *it4;
						//cout<<"reach"<<v[0]<<endl;
						if(abs(v[0]-x[0])<=dw && v[2]<x[2]+v[1])
						{	
							v[2]=x[2]+v[1];//cout<<"EF"<<v[2]<<" "<<v[0]<<" "<<newY<<endl;
							a[newY].erase(v);a[newY].insert(v);
							if(h-newY<=dh && v[2]>maxVal)
								maxVal = v[2];
						}
					}
					
				}
				else 
					break;
			}			
		}		
	}
	/*for (it = yset.begin(); it !=yset.end(); ++it)
	{
		int y = *it; 
		set<vector<int>,compare>::iterator it2;
		cout<<"y: "<<y<<endl;
		for (it2 = a[y].begin(); it2 !=a[y].end(); ++it2) {
			vector<int> x = *it2;
			cout<<x[0]<<" "<<x[2]<<endl;
		}
	}*/
	cout<<maxVal<<endl;
    return 0;
}
