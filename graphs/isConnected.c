#include<stdio.h>
#include<stdlib.h>
void addEdge(int G[5][5],int i,int j){
    G[i][j]=1;
}
int Connected(int G[5][5],int V){
    int count=0;
    for(int i=1;i<=V;i++){
        count=0;
        for(int j=1;j<=V;j++){
            if(G[i][j]==0){
                count++;
            }
        }
        if(count==V){
            int count1=0;
            for(int k=1;k<=V;k++){
                if(G[k][i]==0){
                    count1++;
                }
            }
            if(count1==V){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    int V=4;
    int a[4][2]={{1,2},{1,3},{2,3}};
    int G[5][5]={};
    for(int i=0;i<V;i++){
        addEdge(G,a[i][0],a[i][1]);
    }
    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int r=Connected(G,V);
    if(r==1){
        printf("Graph is connected");
    }
    if(r==0){
        printf("Graph is not connected");
    }
    return 0;
}