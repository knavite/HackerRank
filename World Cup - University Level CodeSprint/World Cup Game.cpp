#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define N 1000010
long long a[N];
bool visited[N];
long long sumx[N];
long long maxx[N];
long long sum=0;
map<int,vector<int>> g;
long long dfs(int s){
    visited[s]=true;
    long long sumt=0;
    long long  xx=0;
    vector<int> vec=g[s];
    vector<int>::iterator it;
    for(it = vec.begin() ; it!=vec.end() ; it++){
        if(!visited[*it]){
            xx=dfs(*it);
            maxx[s]=max(maxx[s],xx);
            sumt+=xx;
        }
    }
    sumt+=a[s];
    maxx[s]=max(maxx[s],sum-sumt);
    return sumx[s]=sumt;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,u,v;
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=1;i<n;i++){
        cin>>u>>v;
        vector<int> vc;
        if(g.find(u)!=g.end()){
            vc=g[u];
        }
        vc.push_back(v);
        g[u]=vc;
        vc.clear();
        if(g.find(v)!=g.end()){
            vc=g[v];
        }
        vc.push_back(u);
        g[v]=vc;
    }
    /*map<int,vector<int>>::iterator it1;
    for(it1=g.begin();it1!=g.end();it1++){
        vector<int>::iterator it;
        cout<<"first "<<it1->first<<"\n";
        vector<int> vcs=it1->second ;
        for(it =vcs.begin(); it!=vcs.end() ; it++){
            cout<<*it<<" ";
        }
        cout<<"\n";
    }*/
    dfs(1);
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(maxx[i]>0){
           ans=max(ans,sum-maxx[i]); 
        }
    }
    cout<<ans<<"\n";
    return 0;
}
