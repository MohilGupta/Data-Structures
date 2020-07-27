#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size,front,rear;
    int *Q;
};
void create(struct queue *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int *)malloc(q->size*sizeof(int));
}
void enqueue(struct queue *q,int data){
    if(q->rear==q->size-1){
        return;
    }
    else{
        q->rear++;
        q->Q[q->rear]=data;
    }
}
int dequeue(struct queue *q){
    int x=-1;
    if(q->front==q->rear){
        return x;
    }
    else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
int isEmpty(struct queue q){
    return q.front==q.rear;
}
int bfs(int G[4][4],int start,int V){
    struct queue q;
    create(&q,100);
    int visited[4]={};
    enqueue(&q,start);
    visited[start]=1;
    while(!isEmpty(q)){
        int u=dequeue(&q);
        for(int i=1;i<=V;i++){
            if(G[u][i]==1 && visited[i]==1){
                return i;
            }
            if(G[u][i]==1 && visited[i]==0){
                enqueue(&q,i);
                visited[i]=1;
            }
        }
    }
}
void addEdge(int G[4][4],int i,int j){
    G[i][j]=1;
}
int main(){
    int V=3;
    int G[4][4]={{0,0,0,0},
                 {0,0,0,0},
                 {0,0,0,0},
                 {0,0,0,0}};
    int a[3]={2,3,1};
    for(int i=1;i<=V;i++){
        addEdge(G,i,a[i-1]);
    }
    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
    for(int i=1;i<=V;i++){
        printf("%d ",bfs(G,i,V));
    }
    return 0;
}