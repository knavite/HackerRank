#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
struct node {
	int val;
	int count;
};

node maketree(int a[],node tree[],int root,int left,int right) {
	if(left==right) {
		tree[root].val = a[left];
		tree[root].count = 1;
		return tree[root];
	}
	else {
		int mid = (left+right)>>1;
		int leftChild = root<<1;
		int rightChild = (root<<1)|1;
		node leftValue = maketree(a,tree,leftChild,left,mid);
		node rightValue = maketree(a,tree,rightChild,mid+1,right);
		if(leftValue.val > rightValue.val){
			tree[root].count = tree[leftChild].count;
			tree[root].val = leftValue.val;
			return tree[root];
		}
		else if(leftValue.val < rightValue.val){
			tree[root].count = rightValue.count;
			tree[root].val = rightValue.val;
			return tree[root];
		}
		else {
			tree[root].count = tree[rightChild].count+tree[leftChild].count;
			tree[root].val = rightValue.val;
			return tree[root];
		}
	}
}

node query(node tree[],int root,int a,int b,int left,int right) {
	//fprintf(stderr,"%d %d %d %d\n",a,b,left,right);
	if(a<=left && right<=b) {
		return tree[root];
	}
	else {
		int mid = (left+right)>>1;
		int leftChild = root<<1;
		int rightChild = (root<<1)|1;
		node rightValue,leftValue ;
		if(b<=mid) {
			//fprintf(stderr,"here\n");
			leftValue = query(tree,leftChild,a,b,left,mid);
			return leftValue;
		}
		else if(a>mid) {
			//fprintf(stderr,"there\n");
			rightValue = query(tree,rightChild,a,b,mid+1,right);
			return rightValue;
		}
		else {
			//fprintf(stderr,"tear\n");
			leftValue = query(tree,leftChild,a,mid,left,mid);
			rightValue = query(tree,rightChild,mid+1,b,mid+1,right);
			if(leftValue.val > rightValue.val)
				return leftValue;
			else if(leftValue.val < rightValue.val)
				return rightValue;
			else {
				node res;
				res.val = leftValue.val;
				res.count = leftValue.count + rightValue.count;
				return res;
			}
		}
	}
}

int main() {
    int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	node tree[4*n];
	maketree(a,tree,1,1,n);
	/*for(int i=1;i<4*n;i++) {
		cout<<tree[i].val<< " "<<tree[i].count<<endl;
	}*/
	for(int i=0;i<m;i++) {
		int l,r;
		cin>>l>>r;
		node res = query(tree,1,l,r,1,n);
		cout<<res.count<<endl;
	}
    return 0;
}
