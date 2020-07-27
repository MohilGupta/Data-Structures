#include<stdio.h>
#include<stdlib.h>
void addEdge(int G[][6],int i,int j){
    G[i][j]=1;
}
int main(){
    int V=4;
    int G[6][6]={};
    int A[][2]={{1,2},{2,3},{3,4},{4,1}};
    for(int i=0;i<V;i++){
        addEdge(G,A[i][0],A[i][1]);
    }
    return 0;
}