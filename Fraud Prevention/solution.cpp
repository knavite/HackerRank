#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

typedef struct node {
	int orderId;
	int dealId;
	string email;
	string streetAddress;
	string city;
	string state;
	string zip;
	long cardNumber;
	struct node *next;
} Node;


int compare(Node a,Node b) {
//cout<<a.orderId<<" "<<b.orderId<<a.streetAddress<<" "<<b.streetAddress<<a.dealId<<" "<<b.dealId<<" "<<a.streetAddress.compare(b.streetAddress)<<endl;
	if(a.dealId == b.dealId && a.email.compare(b.email)==0)
	{return 1;}
	if(a.dealId == b.dealId && a.streetAddress.compare(b.streetAddress)==0 && a.city.compare(b.city)==0 && a.state.compare(b.state)==0 && a.zip.compare(b.zip)==0)
		return 1;
	return 0;
}


int main() {
    int n;
	string str;
	Node *root=NULL;
	cin>>n;getline(cin,str);
	Node * dataa = new Node[n];
	int flag[n]={0};
	for(int i=0;i<n;i++) {
		Node data;
		getline(cin,str);
		vector<string> x = split(str, ',');
		data.orderId = atoi(x[0].c_str());
		data.dealId = atoi(x[1].c_str());
		data.email = x[2];
		transform(data.email.begin(), data.email.end(), data.email.begin(), ::tolower);
		char tempEmail[data.email.size()+1];
		int tempI = 0,atFound = 0;
		for(int j=0;j<data.email.size();j++) {
			if(data.email.at(j)=='.' && atFound==0)
				continue;
			if(data.email.at(j)=='+') {
				while(data.email.at(j)!='@')
					j++;
			}
			if(data.email.at(j)=='@')
				atFound = 1;
			tempEmail[tempI++] = data.email.at(j);
		}
		tempEmail[tempI] = '\0';
		data.email = string(tempEmail);
		
		data.streetAddress = x[3];
		transform(data.streetAddress.begin(), data.streetAddress.end(), data.streetAddress.begin(), ::tolower);
		replaceAll(data.streetAddress,"street","st.");
		replaceAll(data.streetAddress,"road","rd.");
		data.city = x[4];
		transform(data.city.begin(), data.city.end(), data.city.begin(), ::tolower);
		
		data.state = x[5];
		transform(data.state.begin(), data.state.end(), data.state.begin(), ::tolower);
		replaceAll(data.state,"illinois","il");
		replaceAll(data.state,"california","ca");
		replaceAll(data.state,"new york","ny");
		data.zip = x[6];
		replaceAll(data.zip,"-","");
		data.cardNumber = atol(x[7].c_str());
		data.next = NULL;
		dataa[i] = data;
		for(int j=0;j<i;j++) {
			if(compare(data,dataa[j])==1) {
				flag[j]=1;
				flag[i]=1;
			}
		}
		
	}
	int ii=0;
	for(int j=0;j<n;j++) {
		if(flag[j]==1) {
			if(ii!=0)
				cout<<","<<j+1;
			else {
				cout<<j+1;ii++;
				}
		}
	}
    return 0;
}
