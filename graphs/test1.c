#include <stdio.h>
#include <stdlib.h>
void maximum(int G[5][5]){
    int degree[5];
    int sum=0;
    for(int i=1;i<5;i++){
        for(int j=1;j<5;j++){
            sum=sum+G[i][j];
        }
        degree[i]=sum;
        sum=0;
    }
    for(int i=1;i<5;i++){
        printf("%d ",degree[i]);
    }
}
int degree(int G[5][5],int node){
    int count=0;
    for(int i=0;i<5;i++){
        if(G[node][i]==1){
            count++;
        }
    }
    return count;
}
void addEdge(int G[5][5],int source,int destination){
    G[source][destination]=1;
    G[destination][source]=1;
}
int main(){
    int A[4][2]={{1,2},{2,3},{1,4},{2,4}};
    int G[5][5]={};
    for(int i=0;i<4;i++){
        addEdge(G,A[i][0],A[i][1]);
    }
    for(int i=1;i<5;i++){
        for(int j=1;j<5;j++){
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
    printf("\n%d",degree(G,2));
    printf("\n");
    maximum(G);
    return 0;
}
