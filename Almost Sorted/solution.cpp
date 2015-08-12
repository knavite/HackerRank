#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void reverse(int arr[],int i,int j)
{
	for(int k=i;k<=(j+i)/2;k++) {
		int t=arr[k];
		arr[k]=arr[j-k+i];
		arr[j-k+i]=t;
	}
}

int check(int arr[],int n)
{
	int flag=1;
	for(int i=0;i<n+1;i++) {
		if(arr[i]>arr[i+1])
		{
			flag=0;
			break;
		}
	}
	return flag;
}

void swap(int arr[],int i,int j) {
	int t=arr[i];
	arr[i]=arr[j];
	arr[j]=t;
}

int reverseAndCheck(int arr[],int n,int i,int j)
{
	reverse(arr,i,j);
	return check(arr,n);
}

int SwapAndCheck(int arr[],int n,int i,int j)
{
	swap(arr,i,j);
	return check(arr,n);
}

int main() {
    int n;
	cin>>n;
	int arr[n+2];
	for(int i=1;i<=n;i++) {
		cin>>arr[i];
	}
	arr[0]=-1;
	arr[n+1]=10000000;
	
	int bothSmallCnt =0 , bothBigCnt = 0;
	int bigFound=-1,smallFound=-1,secBigFound=-1,secSmallFound=-1;
	for(int i=1;i<=n;i++) {
		if(arr[i]<arr[i-1] && arr[i]<arr[i+1])
		{
			bothSmallCnt++;
			if(smallFound == -1)
				smallFound=i;
			else
				secSmallFound = i;
		}
		if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
		{
			bothBigCnt++;
			if(bigFound == -1)
				bigFound=i;
			else
				secBigFound = i;
		}
	}
	if(bothBigCnt==0 && bothSmallCnt==0)
		cout<<"yes\n";
	else if(bothBigCnt==1 && bothSmallCnt==1 && reverseAndCheck(arr,n,bigFound,smallFound))
	{
		cout<<"yes\n";
		if(bigFound!=smallFound-1)
			cout<<"reverse "<<bigFound<<" "<<smallFound<<endl;
		else
			cout<<"swap "<<bigFound<<" "<<smallFound<<endl;
	}
	else if(bothBigCnt==2 && bothSmallCnt==2 && SwapAndCheck(arr,n,bigFound,secSmallFound)) {
		cout<<"yes\n";
		cout<<"swap "<<bigFound<<" "<<secSmallFound<<endl;
	}
	else
	cout<<"no\n";
    return 0;
}
