#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct graph{
    int V;
    struct node **array;
    int *visited;
};
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
struct graph *createGraph(int V){
    struct graph *graph=(struct graph *)malloc(sizeof(struct graph));
    graph->V=V;
    graph->array=(struct node **)malloc(V*sizeof(struct node *));
    graph->visited=(int *)malloc(V*sizeof(int *));
    for(int i=0;i<V;i++){
        graph->array[i]=NULL;
        graph->visited[i]=0;
    }
    
    
    return graph;
}
struct node* createNode(int v)
{
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}
void addEdge(struct graph* graph, int src, int dest)
{

    struct node* newNode = createNode(dest);
    newNode->next = graph->array[src];
    graph->array[src] = newNode;
 

    newNode = createNode(src);
    newNode->next = graph->array[dest];
    graph->array[dest] = newNode;
}
int connected(struct graph *graph,int start,int V){
    struct queue q;
    create(&q,100);
    int a[10]={};
    graph->visited[start]=1;
    a[start]=start;
    enqueue(&q,start);
    while(!isEmpty(q)){
        int u=dequeue(&q);
        struct node *temp=graph->array[u];
        while(temp){
            int adjvertex=temp->data;
            if(graph->visited[adjvertex]==0){
                a[adjvertex]=adjvertex;
                graph->visited[adjvertex]=1;
                enqueue(&q,adjvertex);
            }
            temp=temp->next;
        }
    }
    for(int i=1;i<=V;i++){
        if(a[i]==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int V=4;
    struct graph *G=createGraph(V+1);
    addEdge(G, 1, 2);
    addEdge(G, 1, 3);
    addEdge(G, 2, 3);
    printf("%d",connected(G,1,V));
    return 0;
}