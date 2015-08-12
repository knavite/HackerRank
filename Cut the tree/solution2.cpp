#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dfs(vector<int> graph[],int visited[],int val[],int sum[],int i)
{
	//cout<<"Called for "<<i<<" "<<visited[2]<<endl;
	visited[i] = 1;
	sum[i]=val[i];
	for(int ii=0;ii<graph[i].size();ii++) {
		if(visited[graph[i][ii]]==0)
			sum[i] += dfs(graph,visited,val,sum,graph[i][ii]);
	}
	return sum[i];
}


int main() {
    int n;
	cin>>n;
	vector<int> graph[n+1];
	int val[n+1],sum=0;
	int visited[n+1],subsum[n+1];
	for(int i=1;i<=n;i++) {
		cin>>val[i];
		sum+=val[i];
		visited[i]=0;
	}
	
	for(int i=0;i<n-1;i++) {
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	
	dfs(graph,visited,val,subsum,1);
	
	int mindiff = 1000000000;
	for(int i=2;i<=n;i++) {
		int sumi = sum - subsum[i];
		int diff = abs(sumi-subsum[i]);
		//cout<<subsum[i]<<" "<<sumi<<" "<<diff<<endl;
		
		if(diff<mindiff) 
			mindiff=diff;
	}
	cout<<mindiff<<endl;
    return 0;
}
