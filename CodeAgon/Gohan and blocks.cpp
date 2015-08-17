#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

string orig;
int cnt=0,dCnt=0;
vector<string> res;
map<string,int> mymap;
void compute(string str,string newStr, stack<char> s,int len,int curr) {
	if(newStr.size()==len) {
		if(mymap[newStr]==0) {
			mymap[newStr]=1;
			dCnt++;
		}
		res.push_back(newStr);
		if(orig==newStr)
			cnt++;
	}
	else {
		//cout<<s.size()<<" size "<<endl;
		if(!s.empty()) {
			char popped;
			popped = s.top();
			//cout<<s.top()<<" top "<<endl;
			newStr.push_back(popped);
			s.pop();
			compute(str,newStr,s,len,curr);
			s.push(popped);
			newStr = newStr.substr(0,newStr.size()-1);
		}
		if(str.size()>0) {
			s.push(str.at(0));
			str = str.substr(1,str.size()-1);
			//cout<<str<<" hello "<<endl;
			curr++;
			compute(str,newStr,s,len,curr);
		}
	}
}

int main() {
    string str;
	cin>>str;
	orig = str;
	stack<char> s;
	string newStr;
	int curr = 0;
	compute(str,newStr,s,str.size(),curr);
	//cout<<res.size();
	/*for(int i=0;i<res.size();i++)
		cout<<res[i]<<" h ";*/
	cout<<cnt<<" "<<dCnt<<endl;
    return 0;
}
