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
void bfs(int G[][10],int start,int V){
    struct queue q;
    create(&q,100);
    int visited[5]={};
    printf("%d ",start);
    enqueue(&q,start);
    visited[start]=1;
    while(!isEmpty(q)){
        int u=dequeue(&q);
        for(int i=1;i<=V;i++){
            if(G[u][i]==1 && visited[i]==0){
                printf("%d ",i);
                enqueue(&q,i);
                visited[i]=1;
            }
        }
    }
}
void addEdge(int G[10][10],int i,int j){
    G[i][j]=1;
}
int main(){
    int A[][2]={{1,2},{2,3},{3,2}};
    int G[4][4]={{0,0,0,0},
                 {0,0,1,0},
                 {0,0,0,1},
                 {0,0,1,0}};
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
    bfs(G,2,V);
    return 0;
}