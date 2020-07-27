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
void dfs(struct graph *graph,int start){
    struct node *temp=graph->array[start];
    graph->visited[start]=1;
    printf("%d ",start);
    while(temp){
        int adj=temp->data;
        if(graph->visited[adj]==0){
            dfs(graph,adj);
        }
        temp=temp->next;
    }
}
int main(){
    int V=4;
    struct graph *G=createGraph(V+1);
    addEdge(G, 1, 2);
    addEdge(G, 1, 3);
    addEdge(G, 2, 3);
    dfs(G,1);
    return 0;
}