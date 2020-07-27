#include<stdlib.h>
#include<stdio.h>
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
struct node{
    int data;
    struct node *next;
};
struct graph{
    int V;
    struct node **array;
    int *visited;
};
struct node *newNode(int data){
    struct node *newnode=(struct newNode *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
struct graph *createGraph(int V){
    struct graph *graph=(struct graph *)malloc(sizeof(struct graph));
    graph->V=V;
    graph->array=(struct node **)malloc(graph->V*sizeof(struct node *));
    for(int i=0;i<V;i++){
        graph->array[i]=NULL;
    }
    graph->visited=(int *)malloc((V+1)*sizeof(int));
    for(int i=0;i<=V;i++){
        graph->visited[i]=0;
    }
    return graph;
}
void addedge(struct graph *graph,int src,int dest){
    struct node *newnode=newNode(dest);
    newnode->next=graph->array[src];
    graph->array[src]=newnode;

    newnode=newNode(src);
    newnode->next=graph->array[dest];
    graph->array[dest]=newnode;
}
void BFS(struct graph *graph,int node){
    struct queue q;
    int u;
    create(&q,100);
    printf("%d",graph->array[node]->data);
    enqueue(&q,graph->array[node]->data);
    graph->visited[node]=1;
    while(!isEmpty(q)){
        u=dequeue(&q);
        struct node *temp=graph->array[u];

    }
}
