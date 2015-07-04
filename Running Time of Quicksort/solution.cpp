#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int insertionSort(int N, int arr[]) {
    int i,j;
    int value;
    int cnt=0;
    for(i=1;i<N;i++)
    {
        value=arr[i];
        j=i-1;
        while(j>=0 && value<arr[j]) //Added Equal to
        {
            arr[j+1]=arr[j];
            j=j-1;
            cnt++;
        }
        arr[j+1]=value;
    }
    
    return cnt;
   
}

int partition(int *a, int l, int r,int n,int &swap) {

    int i, j, p, t;

    p = a[r];
    i = l - 1;

    for(j =l; j <= r-1; j++) {
        if(a[j] <= p) {
            i++;
			swap++;
            t = a[j];
            a[j] = a[i];
            a[i] = t;
        }
    }
	swap++;
    t = a[i+1];
    a[i+1] = a[r];
    a[r] = t;
    return i+1;
}

int quicksort(int a[],int start,int end,int n) {
	int swap = 0;
	if(start<end) {
		int mid = partition(a,start,end,n,swap);
		swap +=quicksort(a,start,mid-1,n);
		swap +=quicksort(a,mid+1,end,n);
	}
	return swap;
}

int main(void) {

    int N;
    scanf("%d", &N);
    int arr[N],arr2[N], i;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
		arr2[i]=arr[i];
    }

    cout<<insertionSort(N, arr2) - quicksort(arr,0,N-1,N)<<endl;

    return 0;
}
