#include <iostream>
#include <cstring>
using namespace std;
int find(int ds[],int u) {
	if(ds[u]>=0) {
		ds[u]=find(ds,ds[u]);
		return ds[u];
	}
	return u;
}

void unionn(int ds[],int u,int v)
{
	int r = find(ds,u);
	int s = find(ds,v);
	if(r>s) {
		ds[s] += ds[r];
		ds[r] = s;	
	}
	else if(r<s) {
		ds[r] +=ds[s];
		ds[s] = r;
	}
}



int main() {
	int n;
	cin>>n;
	int ds[n];
	for(int i=0;i<n;i++)
		ds[i]=-1;
	int m;
	cin>>m;
	for(int i=0;i<m;i++) {
		char Q;
		cin>>Q;
		if(Q=='M') {
			int u,v;
			cin>>u>>v;
			unionn(ds,u-1,v-1);
		}
		else {
			int u;
			cin>>u;
			cout<<-1*ds[find(ds,u-1)]<<endl;
		}
		
	}
	return 0;
}