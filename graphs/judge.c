#include<stdio.h>
#include<stdlib.h>
void addedge(int G[][10],int start,int end){
    G[start][end]=1;
}
int judge(int n,int a[2][2],int asize){
    int G[10][10]={};
    int count,col=0;
    for(int i=0;i<asize;i++){
        addedge(G,a[i][0],a[i][1]);
    }
    for(col=1;col<=n;col++){
        count=0;
        for(int row=1;row<=n;row++){
            if(G[row][col]==1){
                count++;
            }
            if(count==n-1){
                break;
            }
        }
    }
    if(count==n-1){
        for(int k=1;k<=n;k++){
            if(G[col-1][k]==1){
                return -1;
            }
        }
        return col-1;
    }
    else
        return -1;
}

int main(){
    int a[2][2]={{1,3},{2,3}};
    printf("%d",judge(3,a,2));
    return 0;
}