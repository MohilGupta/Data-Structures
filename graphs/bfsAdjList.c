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
void bfs(struct graph *graph,int start){
    struct queue q;
    create(&q,100);
    printf("%d ",start);
    enqueue(&q,start);
    graph->visited[start]=1;
    while(!isEmpty(q)){
        int u=dequeue(&q);
        struct node *temp=graph->array[u];
        while(temp){
            int adjvertex=temp->data;
            if(graph->visited[adjvertex]==0){
                printf("%d ",adjvertex);
                graph->visited[adjvertex]=1;
                enqueue(&q,adjvertex);
            }
            temp=temp->next;
        }
    }
}
void Degree(struct graph *graph,int V){
    int A[10]={};
    int count=0;
    struct node * temp;
    for(int i=1;i<=V;i++){
        count=0;
        temp=graph->array[i];
        while(temp){
            count++;
            temp=temp->next;
        }
        A[i]=count;
    }
    for(int i=1;i<=V;i++){
        printf("%d ",A[i]);
    }
}
int find(struct graph *g,int node,int V){
    struct node *temp=NULL;
    for(int i=1;i<=V;i++){
        temp=g->array[i];
        while(temp){
            if(temp->data==node){
                return 1;
            }
            temp=temp->next;
        }
    }
    return 0;
}
int isConnected(struct graph *graph,int V){
    struct node *temp=NULL;
    int count=0;
    for(int i=1;i<=V;i++){
        count=0;
        temp=graph->array[i];
        while(temp){
            count++;
            temp=temp->next;
        }
        if(count==0){
            if(find(graph,i,V)==0){
                return 0;
            }
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
    bfs(G,1);
    printf("\n");
    Degree(G,V);
    if(isConnected(G,V)==1){
        printf("\nconnected");
    }
    else{
        printf("\nnot connected");
    }
    return 0;
}