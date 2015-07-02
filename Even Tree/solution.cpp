#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int count(vector<int> graph[],int root) {
	int cnt =1;
	for(int i=0;i<graph[root].size();i++)
		cnt+=count(graph,graph[root][i]);
	return cnt;
}

int modifiedBfs(vector<int> graph[],int root) {
	queue<int> q;
	q.push(root);
	int cnt=0;
	while(!q.empty()) {
		int current = q.front();
		q.pop();
		for(int i=0;i<graph[current].size();i++) {
			if(count(graph,graph[current][i])%2==0)
				cnt++;
			q.push(graph[current][i]);
		}
	}
	return cnt;
}

int main() {
    int n,m;
	cin>>n>>m;
	vector<int> graph[n+1];
	int flag[n+1]={0};
	for(int i=0;i<m;i++) {
		int a,b;
		cin>>a>>b;
		graph[b].push_back(a);
		flag[b]=1;
	}	
	int selected = 1;
	for(int i=1;i<n;i++) {
		if(flag[i]==0)
			selected=i;
			break;
	}
	cout<<modifiedBfs(graph,selected);
    return 0;
}
