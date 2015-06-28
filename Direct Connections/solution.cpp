#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;

struct data {
	long long x;
	long long population;
	int index;
};

struct node {
	long long count;
	long long sum;
};
int cmpx(data a,data b) {
	return a.x<b.x;
}

int cmpp(data a,data b) {
	return a.population<b.population;
}

void insert (node tree[],long long root,int l,int r,data d)
{
	
	tree[root].count++;
	tree[root].sum= (tree[root].sum+d.x)%MOD;
	if(l==r)
		return;
	int mid = (l+r)>>1;
	if(d.index<=mid) 
		insert(tree,root<<1,l,mid,d);
	else
		insert(tree,(root<<1)|1,mid+1,r,d);
}

node query(node tree[],long long  root,long long  a,long long  b, long long  l,long long  r) {
	//cout<<a<<" "<<b<<" "<<l<<" "<<r<<" "<<root<<endl;
	if(a==l && b==r)
		return tree[root];
	else {
		long long  mid = (l+r)>>1;
		long long left = root<<1;
		long long right = (root<<1)|1;
		if(b<=mid) 
			return query(tree,left,a,b,l,mid);
		else if(a>mid)
			return query(tree,right,a,b,mid+1,r);
		else {
			node templ = query(tree,left,a,mid,l,mid);
			node tempr = query(tree,right,mid+1,b,mid+1,r);
			node temp;
			temp.count = templ.count + tempr.count;
			temp.sum = (templ.sum +tempr.sum)%MOD;
			return temp;
		}
	}
}
int main() {
    int t;
	cin>>t;
	while(t--) {
		int N;
		cin>>N;
		data a[N];
		for(int i=0;i<N;i++)
			cin>>a[i].x;
		for(int i=0;i<N;i++)
			cin>>a[i].population;
		sort(a,a+N,cmpx);
		for(int i=0;i<N;i++)
			a[i].index = i+1;
		sort(a,a+N,cmpp);
		node tree[4*N];
		for(int i=0;i<N*4;i++)
			tree[i].count =tree[i].sum=0;
		long long sum = 0;
		for(int i=0;i<N;i++) {
		
			node templ = query(tree,1,1,a[i].index,1,N);
			long long leftSum = (templ.count*a[i].x)%MOD - templ.sum;
			if(leftSum<0)
				leftSum = leftSum+MOD;
			node tempr = query(tree,1,a[i].index,N,1,N);
			long long rightSum = tempr.sum - ((tempr.count*a[i].x)%MOD);
			if(rightSum<0)
				rightSum = rightSum+MOD;
			sum = (sum+(((rightSum+leftSum)%MOD)*a[i].population)%MOD)%MOD;
			insert(tree,1,1,N,a[i]);
			/*for(int ii=0;ii<N*4;ii++)
			cout<<tree[ii].count <<" "<<tree[ii].sum<<" ";
			cout<<endl;
			cout<<leftSum<<" "<<rightSum<<" "<<a[i].x<<endl;cout<<sum<<endl;*/
		}
		cout<<sum<<endl;
	}
	return 0;
}
