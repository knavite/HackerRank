#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr,int start,int end) {
    int pivot = start;
	vector<int> temp;
    for(int i=start+1;i<=end;i++) {
		if(arr[i]<arr[pivot])
			temp.push_back(arr[i]);
	}
	temp.push_back(arr[pivot]);
	
	int mid = start+temp.size()-1;
	for(int i=start+1;i<=end;i++) {
		if(arr[i]>arr[pivot])
			temp.push_back(arr[i]);
	}
	for(int i=start;i<=end;i++) {
		arr[i]=temp[i-start];
	}
	return mid;
}

void quickSort(vector <int>& arr,int start,int end) {
	//fprintf(stderr,"%d %d\n",start,end);
	if(start<end) {
		int mid = partition(arr,start,end);
		quickSort(arr,start,mid-1);
		quickSort(arr,mid+1,end);
		for(int i = start; i <= (int)end; ++i) {
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
    int n;
    scanf("%d", &n);

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr,0,n-1);
	
    return 0;
}
