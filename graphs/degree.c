#include<stdio.h>
#include<stdlib.h>
void addEdge(int G[5][5],int i,int j){
    G[i][j]=1;
}
int inDegree(int G[5][5],int node){
    int count=0;
    for(int i=1;i<=4;i++){
        if(G[node][i]==1){
            count++;
        }
    }
    return count;
}
int outDegree(int G[5][5],int node){
    int count=0;
    for(int i=1;i<=4;i++){
        if(G[i][node]==1){
            count++;
        }
    }
    return count;
}
int main(){
    int A[4][2]={{1,2},{2,3},{3,4},{4,1}};
    int G[5][5]={};
    for(int i=0;i<4;i++){
        addEdge(G,A[i][0],A[i][1]);
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
    printf("%d",outDegree(G,4));
    return 0;
}



