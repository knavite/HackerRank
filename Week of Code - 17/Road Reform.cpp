#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef  long long ull;
 
struct Node
{
    ull dest;
    ull weight;
	Node(ull x,ull y) : dest(x), weight(y) {}
};
 
struct MinHeapNode
{
    ull  v;
    ull dist;
};
 
struct MinHeap
{
    ull size;      
    ull capacity;  
    ull *pos;     
    struct MinHeapNode **array;
};
 

struct MinHeapNode* newMinHeapNode(ull v, ull dist)
{
    struct MinHeapNode* minHeapNode =
           (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}
 

struct MinHeap* createMinHeap(ull capacity)
{
    struct MinHeap* minHeap =
         (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->pos = (ull *)malloc(capacity * sizeof(ull));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array =
         (struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}
 
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
 
void minHeapify(struct MinHeap* minHeap, ull idx)
{
    ull smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;
 
    if (left < minHeap->size &&
        minHeap->array[left]->dist < minHeap->array[smallest]->dist )
      smallest = left;
 
    if (right < minHeap->size &&
        minHeap->array[right]->dist < minHeap->array[smallest]->dist )
      smallest = right;
 
    if (smallest != idx)
    {
        MinHeapNode *smallestNode = minHeap->array[smallest];
        MinHeapNode *idxNode = minHeap->array[idx];
 
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;
 
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
 
        minHeapify(minHeap, smallest);
    }
}
 
ull isEmpty(struct MinHeap* minHeap)
{
    return minHeap->size == 0;
}
 

struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    if (isEmpty(minHeap))
        return NULL;
 
    struct MinHeapNode* root = minHeap->array[0];
 
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
 
    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;
 
    --minHeap->size;
    minHeapify(minHeap, 0);
 
    return root;
}
 

void decreaseKey(struct MinHeap* minHeap, ull v, ull dist)
{
    ull i = minHeap->pos[v];

    minHeap->array[i]->dist = dist;
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
    {
        minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
        swapMinHeapNode(&minHeap->array[i],  &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
 
bool isInMinHeap(struct MinHeap *minHeap, ull v)
{
   if (minHeap->pos[v] < minHeap->size)
     return true;
   return false;
}
 
void printArr(ull dist[], ull n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i) {
        printf("%d \t\t %d\t", i, dist[i]);
		
		cout<<endl;
	}
}
 
ull dijkstra(ull V, vector<Node> graph[], ull src,ull dist[],ull destination)
{
    struct MinHeap* minHeap = createMinHeap(V);
 
    for (int v = 0; v < V; ++v)
    {
        dist[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }
 
    minHeap->array[src] = newMinHeapNode(src, dist[src]);
    minHeap->pos[src]   = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);
 
    minHeap->size = V;
 
    while (!isEmpty(minHeap))
    {
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        ull u = minHeapNode->v; 
		for(int i=0;i<graph[u].size();i++) {
			ull v = graph[u][i].dest;
			if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && 
                                          graph[u][i].weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + graph[u][i].weight;
                decreaseKey(minHeap, v, dist[v]);
            }
		}
    }
	
	//-----------------------
	
   // printArr(dist, V);
	return dist[destination];
}
 

int main() {
    ull n,m;
    cin>>n>>m;
	vector<Node> g[n+1];
	vector<ull> edgeList[m];
	for(int i=0;i<m;i++) {
		ull a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		edgeList[i].push_back(a);
		edgeList[i].push_back(b);
		edgeList[i].push_back(c);
		Node n1(b,c);
		g[a].push_back(n1);
		Node n2(a,c);
		g[b].push_back(n2);
	}
	ull dist1[n];
	ull minVal = dijkstra(n,g,0,dist1,n-1);
	//cout<<minVal<<endl;
	ull dist2[n];
	dijkstra(n,g,n-1,dist2,0);
	unsigned long long  cnt=0;
	ull src[n];
	ull dst[n];
	memset(src,0,n*sizeof(ull));
	memset(dst,0,n*sizeof(ull));
	src[n-1]=1;
	//dst[0]=1;
	for(int i=0;i<m;i++) {
		ull a=edgeList[i][0];
		ull b=edgeList[i][1];
		ull c=edgeList[i][2];
		if(dist1[a]+dist2[b] < dist1[b] + dist2[a]) {
			//cout<<dist1[a]<<" d1 "<<dist2[b]<<endl;
			ull val=minVal - (dist1[a]+dist2[b]);
			if(val<=c && val>0)
				cnt+=val-1;
		}
		else {
			//cout<<dist1[b]<<" d2 "<<dist2[a]<<endl;
			ull val=minVal - (dist1[b]+dist2[a]);
			if(val<=c && val>0)
				cnt+=val-1;
		}
		if(a==0)
				src[b] =1;
			if(b==0)
				src[a] = 1;
			if(a==n-1)
				dst[b] = 1;
			if(b==n-1)
				dst[a] = 1;
		//cout<<"Cnt"<<cnt<<endl;
	}
	for(int i=0;i<n;i++) {
		if(src[i]==0 && i!=0)
			if(((minVal - dist2[i])-1)>0)
				cnt+=(minVal - dist2[i])-1;
		//cout<<cnt<<" D"<<dist2[i]<<endl;
		if(dst[i]==0 && i!=n-1)
			if(((minVal - dist1[i])-1)>0)
				cnt+=(minVal - dist1[i])-1;
		//cout<<cnt<<" e"<<dist1[i]<<endl;
	}
	cout<<cnt<<endl;
    return 0;
}
