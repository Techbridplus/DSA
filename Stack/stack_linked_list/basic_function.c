#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *next;
}*top=NULL;
int isEmpty();
int isFull();
//...
void push(int data){
    
    if(isFull()){
        printf("\nstack overflow");
        return;
    }
struct stack*node=malloc(sizeof(struct stack));
node->data=data;
node->next=NULL;

node->next=top;
top=node;
}
//...
void pop(){
    if(isEmpty()){
        printf("\nstack underflow");
        return;
    }
    struct stack*temp=top;
    top=top->next;
    free(temp);
    temp=NULL;
}

//...
void print(){
    struct stack*ptr=top;
    if(ptr==NULL){
        printf("\nstack underflow");
    }
    while(ptr){
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    push(100);
print();
    
    return 0;
}
//...
int isFull(){
    struct stack*node=malloc(sizeof(struct stack));
    if(node==NULL){
        return 1;
    }else{
        return 0;
    }
}
//...
int isEmpty(){
    if(top==NULL){
        return 1;
    }else{
        return 0;
    }
}
//...