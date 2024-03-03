#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define Max_vertices 10
struct node{
    int data;
    int visit;
}*vertices[10];
struct edge{
    int weight;
    struct node* E;
    struct edge* next;
}*Edge[10],*pre=NULL,*queue[10];
int front=-1,rear=-1;
void Enqueue(struct edge* data){
    if(rear>Max_vertices){
        printf("\nqueue is full");
        return;
    }
    if(front==-1){
        front=0;
        rear=0;
        queue[front]=data;
    }else{
        queue[++rear]=data;
    }
}
struct edge* Dequeue(){
    if(rear==-1){
        printf("\nQueue is empty");
        return NULL;
    }
    struct edge* temp=queue[rear];
    queue[rear]=NULL;
    rear--;
    return temp;
}


void Initilaize_null(){
    for(int i=0;i<10;i++){
        Edge[i]=NULL;
        Edge[i]->E=NULL;
        Edge[i]->next=NULL;
        Edge[i]->weight=-1;
        queue[i]=NULL;
    }
}
int V=0;
void insert_vertices(int data){
    if(V>Max_vertices){
        printf("\nnot enough space");
        return;
    }
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->visit=0;
    vertices[V++]=temp;
}
void set_Edge(int index,int weight,int vert_index){
    if(weight==-1){
        printf("\nit has no edges");
        return;
    }
    struct edge* temp=(struct edge*)malloc(sizeof(struct edge));
    temp->weight=weight;
    temp->E=vertices[vert_index];
    temp->next=NULL;
    if(Edge[index]==NULL){
    Edge[index]=temp;
    pre=temp;
    }else{
        pre->next=temp;
        pre=pre->next;
    }
}
void BFS_traversal(){
    for(int i=0;i<5;i++){
        struct edge*temp=Edge[i];
        printf("\ndata -> %d ",vertices[i]->data);
       while(temp){
        
        printf("\nweight between vertex %d and %d is %d",vertices[i]->data,temp->E->data,temp->weight);
        temp->E->visit=1;
        temp=temp->next;
       }
    }
}

int main(){
   insert_vertices(1);
   insert_vertices(2);
   insert_vertices(3);
   insert_vertices(4);
   insert_vertices(5);
   set_Edge(0,10,1);
   set_Edge(0,20,2);
   set_Edge(1,30,3);
   set_Edge(3,40,4);
   set_Edge(4,-1,-1);
   set_Edge(2,50,4);
   set_Edge(2,60,3);
   BFS_traversal();

    return 0;
}