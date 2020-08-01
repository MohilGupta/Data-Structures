#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;


class node{
    public:
        int data;
        node *next;
};

class LinkedList{
    private:
        node *head;
    public:
        LinkedList(vector<int> &v);
        node *search();
        void display();
};

LinkedList::LinkedList(vector<int> &v){
    vector<int>::iterator itr=v.begin()+1;
    head=new node();
    head->data=v.at(0);
    head->next=NULL;
    node *p=head;
    for(itr;itr!=v.end();itr++){
        p->next=new node();
        p=p->next;
        p->data=*itr;
    }
}

node *LinkedList::search(){

}

void LinkedList::display(){
    node *p=head;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main(){
    vector<int> v{10,9,8,7,6,5,4,3,2,1};
    LinkedList *ll=new LinkedList(v);
    ll->display();
    return 0;

}

// struct node{
//     int data;
//     struct node *next;
// };

// int main(){
//     int A[10]={47,20,40,10,34,24,55,67,98,84};
//     struct node *p;
//     struct node *head=(struct node *)malloc(sizeof(struct node));
//     head->data=A[0];
//     head->next=NULL;
//     p=head;
//     for(int i=1;i<10;i++){
//         p->next=(struct node *)malloc(sizeof(struct node));
//         p=p->next;
//         p->data=A[i];
//     }
//     p=head;
//     while(p->next!=NULL){
//         cout<<p->data<<endl;
//         p=p->next;
//     }
//     return 0;
// }

// struct node *create(int A[],int n){
//     struct node *p, *head=new node;
//     head->data=A[0];
//     head->next=NULL;
//     p=head;
//     cout<<" head is "<<head->next<<endl;
//     for(int i=1;i<10;i++){
//         p->next=new node;
//         p=p->next;
//         p->data=A[i];
//         cout<<"node at position "<<i<<" is "<<p->data<<endl;
//     }
//     return head;
// }

// void display(struct node *p){
//     while(p!=NULL){
//         cout<<p->data<<" ";
//         p=p->next;
//     }
// }

// int main(){
//     int A[10]={47,20,40,10,34,24,55,67,98,84};
//     struct node *head=create(A,10);
//     display(head);
// }


 /////* using STL */////