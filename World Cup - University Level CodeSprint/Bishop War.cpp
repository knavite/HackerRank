#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
char a[11][11];
int hash2[20000];
int safemat1[11][11];
int safemat2[11][11];
long long  ans;

void preprocess(int  n,int m){
    int count=0;
    for(int i=m-1;i>=0;i--){
        count++;
        for(int j=0,k=i;j<n&&k<m;j++,k++){
            if(a[j][k]=='*'){
                safemat1[j][k]=++count;
            }else{
                safemat1[j][k]=count;
            }
        }
       }
        for(int i=1;i<n;i++){
            count++;
            for(int j=i,k=0;j<n&&k<m;j++,k++){
                if(a[j][k]=='*'){
                    safemat1[j][k]=++count;
                }else{
                    safemat1[j][k]=count;
                }
            }
        }
        for(int i=0;i<m;i++){
            count++;
            for(int j=0,k=i;j<n&&k>=0;j++,k--){
                if(a[j][k]=='*'){
                    safemat2[j][k]=++count;
                }else{
                    safemat2[j][k]=count;
                }
            }
        }
        for(int i=1;i<m;i++){
            count++;
            for(int j=i,k=m-1;j<n&&k>=0;j++,k--){
                if(a[j][k]=='*'){
                    safemat2[j][k]=++count;
                }else{
                    safemat2[j][k]=count;
                }
            }
        }
}

bool solveBishop(int n,int m,int row){
    if(row>=n){
        return true;
    }
    for(int i=0;i<m;i++){
      //  cout<<"xxxxrow "<<row<<"col "<<i<<"\n";
        if(a[row][i]!='*'&&!(hash2[safemat1[row][i]]==1||hash2[safemat2[row][i]]==1)){
        //    cout<<"row "<<row<<"col "<<i<<"\n";
            a[row][i]='B';
            hash2[safemat1[row][i]]=1;
            hash2[safemat2[row][i]]=1;
            if(solveBishop(n,m,row+1)){
               /*     for(int i=0;i<n;i++){
                         cout<<a[i]<<"\n";
                    }
                cout<<"\n";*/
                ans+=1;
               // return true;
            }
            a[row][i]='.';
            hash2[safemat1[row][i]]=0;
            hash2[safemat2[row][i]]=0;
        }
    }
    return false;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,m;
    //ios_base::sync_with_stdio(false);
    cin>>n>>m;
    int count=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        count=0;
        for(int k=0;k<m;k++){
            if(a[i][k]=='*') count++;
        }
        if(count==m){
            printf("0\n");
            return 0;
        }
    }
    preprocess(n,m);
   /* for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<safemat1[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<safemat2[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    solveBishop(n,m,0);
    /*for(int i=0;i<n;i++){
        cout<<a[i]<<"\n";
    }*/
    cout<<ans<<"\n";
    return 0;
}
