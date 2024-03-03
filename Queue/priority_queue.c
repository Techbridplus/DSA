#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool isempty();
typedef struct priority_queue
{
    int priority;
    int data;
     struct priority_queue* next;
}priority_queue;

priority_queue *front=NULL;

//enqueue function
void enqueue(int data,int priority){
     priority_queue*current=NULL,*ptr=NULL;
    current=( priority_queue*)malloc(sizeof(priority_queue));
    current->data=data;
    current->priority=priority;
    current->next=NULL;
    if(isempty()||priority<front->priority){
        current->next=front;
        front=current;
    }else{
        ptr=front;
        while(ptr->next!=NULL&&priority>=ptr->next->priority){
            ptr=ptr->next;
        }
        current->next=ptr->next;
        ptr->next=current;
    }
    
    current=NULL;
    ptr=NULL;

}

//dequeue function
void dequeue(){
    if(isempty()){
        printf("\nQUEUE is Empty...");
        exit(1);
    }
    priority_queue*ptr=front;
    front=front->next;
    free(ptr);
    ptr=NULL;

}

//isempty function
bool isempty() {
    return front == NULL;
}
//print data
void print(){
    if(isempty()){
        printf("\nPriority Queue is Empty ...");
        exit(1);
    }
    priority_queue*ptr=front;
    while(ptr){
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    enqueue(10,5);
    enqueue(50,5);
    enqueue(20,5);
    enqueue(40,5);
    enqueue(30,5);
   
 
    
   

    print();
    
    return 0;
}