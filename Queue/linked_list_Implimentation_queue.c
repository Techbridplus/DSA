#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
struct queue{
    int data;
    struct queue *next;
}*head=NULL,*tail=NULL;
int count=0;
//isempty prototype
bool isempty();
//enqueue function
void enqueue(int data){
    count++;
    if(isempty()){
        head=(struct queue*)malloc(sizeof(struct queue));
        head->data=data;
        head->next=NULL;
        tail=head;
    }else{
        struct queue*current=(struct queue*)malloc(sizeof(struct queue));
        current->data=data;
        current->next=NULL;
        tail->next=current;
        tail=current;

    }
   
}

//dequeue function
void dequeue(){
    if(isempty()){
        printf("\nsorry we can't delete => queue is empty");
        exit(1);
    }
    struct queue*current=head;
    head=head->next;
    free(current);
    current=NULL;
    count--;
    printf("\n%d data remains",count);
}

//isempty function
bool isempty(){
    if(!head){
        return true;
    }else{
        return false;
    }
}

// print data
void print(){
     printf("\nqueue head %d data elements",count);
    if(isempty()){
        printf("\nqueue is empty !");
        exit(1);
    }
    struct queue* ptr=head;
    while(ptr!=NULL){
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    enqueue(67);
    enqueue(56);
    enqueue(67);
    print();
    dequeue();
    dequeue();
    print();
    return 0;
}