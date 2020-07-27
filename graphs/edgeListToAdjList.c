#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct graph{
    int V;
    struct node **array;
};
struct graph *createGraph(int V){
    struct graph *g=(struct graph *)malloc(sizeof(struct graph));
    g->V=V;
    g->array=(struct node **)malloc(g->V*sizeof(struct node *));
    for(int i=0;i<V;i++){
        g->array[i]=NULL;
    }
    return g;
}
void addEdge(struct graph *g,int source,int destination){
    struct node *node=(struct node *)malloc(sizeof(struct node));
    node->data=destination;
    node->next=g->array[source];
    g->array[source]=node;
}
int main(){
    int V=2;
    struct graph *G=createGraph(V+1);
    int a[2][2]={{1,2},{2,1}};
    for(int i=0;i<2;i++){
        addEdge(G,a[i][0],a[i][1]);
    }
    print(G);
    return 0;
}