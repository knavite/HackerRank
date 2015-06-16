#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Node {
    int arrivalTime,executionTime;
} node;

int compare(node a,node b) {
	return a.arrivalTime < b.arrivalTime;
}

class ComparisonClass {
    public:
	bool operator() (node a, node b) {
        return a.executionTime > b.executionTime;
    }
};

int main() {
    int n;
	cin>>n;
	node C[n];
	for(int i=0;i<n;i++) {
		cin>>C[i].arrivalTime>>C[i].executionTime;
	}
	sort(C,C+n,compare);
	
	int i=0;
	long long currentArrivalTime=C[0].arrivalTime, waitingTime=0;
	priority_queue<node, vector<node>,  ComparisonClass> pq;
	for(int j=0;j<n;j++) {
		while(i<n && C[i].arrivalTime<=currentArrivalTime) {
			pq.push(C[i++]);
		}
		if(pq.size()==0) {
			pq.push(C[i]);
			currentArrivalTime = C[i++].arrivalTime;
		}
		node toScehdule = pq.top();
		pq.pop();
		currentArrivalTime += toScehdule.executionTime;
		waitingTime += (currentArrivalTime - toScehdule.arrivalTime);
	}
	cout<<waitingTime/n<<endl;
    return 0;
}
