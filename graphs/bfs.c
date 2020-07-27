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
void BFS(int G[4][4],int start,int n){
    int u;
    int visited[4]={0,0,0,0};
    struct queue q;
    create(&q,100);
    printf("%d ",start);
    enqueue(&q,start);
    visited[start]=1;
    while(!isEmpty(q)){
        u=dequeue(&q);
        for(int v=1;v<=n;v++){
            if(G[u][v]==1 && visited[v]==0){
                printf("%d ",v);
                visited[v]=1;
                enqueue(&q,v);
            }
        }
    }
}
int main(){
    /*int G[8][8]={{0,0,0,0,0,0,0,0},
                 {0,0,1,1,1,0,0,0},
                 {0,1,0,1,0,0,0,0},
                 {0,1,1,0,1,1,0,0},
                 {0,1,0,1,0,1,0,0},
                 {0,0,0,1,1,0,1,1},
                 {0,0,0,0,0,1,0,0},
                 {0,0,0,0,0,1,0,0}};*/
    int G[4][4]={{0,0,0,0},
                 {0,0,1,0},
                 {0,0,0,1},
                 {0,0,1,0}};
    BFS(G,2,3);
    return 0;
}
