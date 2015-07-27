#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void reverse(int nums[],int start,int end)
{
	for(int i=start;i<=(start+end)/2;i++) {
		int t=nums[i];
		nums[i]=nums[end-(i-start)];
		nums[end-(i-start)]=t;
	}
}

void rotateRight(int* nums, int numsSize, int k) {
	k = k%numsSize;
	reverse(nums,0,numsSize-k-1);
	reverse(nums,numsSize-k,numsSize-1);
	reverse(nums,0,numsSize-1);
}

int main() {
    int R,C,V;
	cin>>R>>C>>V;
	int MAT[R][C];
	int temp;
	for(int i=0;i<R;i++) {
		for(int j=0;j<C;j++)
			cin>>MAT[i][j];
	}  
	int iR=0,iC=0,eR=R-1,eC=C-1;
	while(iR<eR && iC<eC) {
		int mat[3*R+3*C];
		int k=0;
		for(int i=iR;i<=eR;i++) 
			mat[k++] = MAT[i][iC];
		k--;
		for(int i=iC;i<=eC;i++) 
			mat[k++] = MAT[eR][i];
		k--;
		for(int i=eR;i>=iR;i--) 
			mat[k++] = MAT[i][eC];
		k--;
		for(int i=eC;i>=iC;i--) 
			mat[k++] = MAT[iR][i];
		k--;
		if(k!=0)
			rotateRight(mat,k,V);
		k=0;
		for(int i=iR;i<=eR;i++) 
			MAT[i][iC] = mat[k++];
		k--;
		for(int i=iC;i<=eC;i++) 
			MAT[eR][i] = mat[k++];
		k--;
		for(int i=eR;i>=iR;i--) 
			MAT[i][eC] = mat[k++];
		k--;
		for(int i=eC;i>iC;i--) 
			MAT[iR][i] = mat[k++];
		iR++;
		eR--;
		iC++;
		eC--;
	}
	for(int i=0;i<R;i++) {
		for(int j=0;j<C;j++)
			cout<<MAT[i][j]<<" ";
		cout<<endl;
	} 
    return 0;
}
