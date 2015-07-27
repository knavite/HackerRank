#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
	cin>>t;
	while(t--) {
		int R,C,r,c;
		cin>>R>>C;
		char MAT[R][C];
		char temp;
		for(int i=0;i<R;i++) {
			for(int j=0;j<C;j++)
			{	
				cin>>temp;
				while(temp=='\n')
					cin>>temp;
				MAT[i][j]=temp;
			}
		}
		
		cin>>r>>c;
		char mat[r][c];
		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++)
			{
				cin>>temp;
				while(temp=='\n')
					cin>>temp;
				mat[i][j]=temp;
			}
		}
		int found=0;
		for(int i=0;i<R-r+1;i++) 
		{
			for(int j=0;j<C-c+1;j++)
			{
				int flag=0;
				for(int k=0;k<r;k++)
				{
					for(int l=0;l<c;l++)
					{
						if(MAT[i+k][j+l]!=mat[k][l]) {
							flag=1;
							break;
						}
					}
					if(flag==1)
						break;
				}
				if(flag==0) {
					cout<<"YES\n";
					found=1;
					break;
				}
				
			}
			if(found==1)
				break;
		}
		if(found==0)
			cout<<"NO\n";
		
	}
    return 0;
}
