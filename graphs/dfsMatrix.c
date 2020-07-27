#include<stdio.h>
#include<stdlib.h>
void dfs(int G[][10],int start){
    static int visited[10]={};
    printf("%d ",start);
    visited[start]=1;
    for(int v=1;v<=3;v++){
        if(G[start][v]==1 && visited[v]==0){
            dfs(G,v); 
        }
    }
}
void addEdge(int G[10][10],int i,int j){
    G[i][j]=1;
}
int main(){
    int A[][2]={{1,2},{2,3},{3,2}};
    int G[10][10]={};
    int V=3;
    for(int i=0;i<V;i++){
        addEdge(G,A[i][0],A[i][1]);
    }
    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
    dfs(G,1);
    return 0;
}