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
void find(int parent[],int start,int end){
    int x;
    printf("%d ",start);
    x=parent[start];
    while(x!=end){
        printf("%d ",x);
        x=parent[x];
    }
    printf("%d ",x);
}
void bfs(int G[][10],int start,int end,int V){
    struct queue q;
    create(&q,100);
    int visited[10]={};
    int parent[10]={};
    printf("%d ",start);
    enqueue(&q,start);
    visited[start]=1;
    while(!isEmpty(q)){
        int u=dequeue(&q);
        for(int i=0;i<V;i++){
            if(G[u][i]==1 && visited[i]==0){
                printf("%d ",i);
                enqueue(&q,i);
                visited[i]=1;
                parent[i]=u;
            }
        }
    }
    printf("\n");
    for(int i=1;i<=V;i++){
        printf("%d ",parent[i]);
    }
    printf("\n");
    find(parent,end,start);
}
void addedge(int G[10][10],int i,int j){
    G[i][j]=1;
}
int main(){
    int V=8;
    int G[10][10]={};
    addedge(G, 0, 1); 
    addedge(G, 0, 3); 
    addedge(G, 1, 2); 
    addedge(G, 3, 4); 
    addedge(G, 3, 7); 
    addedge(G, 4, 5); 
    addedge(G, 4, 6); 
    addedge(G, 4, 7); 
    addedge(G, 5, 6); 
    addedge(G, 6, 7); 
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
    bfs(G,0,7,V);
    return 0;
}
