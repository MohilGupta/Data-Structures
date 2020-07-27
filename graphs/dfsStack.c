#include <stdio.h>
#include <stdlib.h>
struct Stack
{
 int size;
 int top;
 int *S;
};
void create(struct Stack *st,int size)
{
st->size=size;
 st->top=-1;
 st->S=(int *)malloc(st->size*sizeof(int));
}
void Display(struct Stack st)
{
 int i;
 for(i=st.top;i>=0;i--)
 printf("%d ",st.S[i]);
 printf("\n");

}
void push(struct Stack *st,int x)
{
 if(st->top==st->size-1){
    return;
 }
 else
 {
 st->top++;
 st->S[st->top]=x;
 }
 
}
int pop(struct Stack *st)
{
 int x=-1;

 if(st->top==-1){
    return x;
 }
 else
 {
 x=st->S[st->top--];
 }
 return x;
}
int isEmpty(struct Stack st)
{
 if(st.top==-1){
    return 1;
 }
 return 0;
}
void dfs(int G[][7],int s){
    struct Stack st;
    create(&st,100);
    int visited[7]={0};
    printf("%d ",s);
    visited[s]=1;
    push(&st,s);
    while(!isEmpty(st)){
        int u=pop(&st);

        for(int v=1;v<=7;v++){
            if(visited[v]==0 && G[u][v]==1){
                visited[v]=1;
                printf("%d ",v);
                push(&st,u);
                push(&st,v);
                break;
            }
        }
    }
}
int main(){
    int G[7][7]={{0,0,0,0,0,0,0},
                {0,0,1,1,0,0,0},
                {0,1,0,0,1,0,0},
                {0,1,0,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}};
 dfs(G,4);
    return 0;
}