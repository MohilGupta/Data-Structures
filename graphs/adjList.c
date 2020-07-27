#include<stdio.h>
#include<stdlib.h>
struct adjListNode{
    int data;
    struct adjListNode *next;
};
struct adjList{
    struct adjListNode *head;
};
struct Graph{
    int V;
    struct adjList *array;
};
struct adjListNode *newAdjListNode(int data){
    struct adjListNode *newNode=(struct adjListNode *)malloc(sizeof(struct adjListNode));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
struct Graph *createGraph(int V){
    struct Graph *graph=(struct Graph *)malloc(sizeof(struct Graph));
    graph->V=V;
    graph->array=(struct adjList *)malloc(V*sizeof(struct adjList));
    for(int i=0;i<V;i++){
        graph->array[i].head=NULL;
    }
    return graph;
}
void addedge(struct Graph *graph,int src,int dest){
    struct adjListNode *newNode=newAdjListNode(dest);
    newNode->next=graph->array[src].head;
    graph->array[src].head=newNode;

    newNode=newAdjListNode(src);
    newNode->next=graph->array[dest].head;
    graph->array[dest].head=newNode;
}
void print(struct Graph *graph){
    for(int v=0;v<graph->V;v++){
        struct adjListNode *temp=graph->array[v].head;
        printf("\nAdjancey list of %d\n",v);
        while(temp){
            printf("->%d",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main(){
    int V=5;
    struct Graph *G=createGraph(V);
    addedge(G,0,5);
    addedge(G,0,1);
    addedge(G,1,2);
    print(G);
    return 0;
}