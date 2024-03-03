#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 5
int arr[MAX];
int front=-1,rear=-1;
bool isempty();
bool isfull();
int count=0;
//enqueue function
void enqueue(int data){
    if(!isfull()){
        count++;
        if(front==-1){
            front++;
        }else if(rear==MAX-1){
            rear=-1;
        }
        rear++;
        arr[rear]=data;
    }else{
        printf("\nqueue is full ! => %d is not added to queue",data);
        exit(1);
    }
}

//dequeue function
void dequeue(){
    if(isempty()){
       
        printf("\nsorry we can't delete => queue is empty");
        exit(1);
    }
    count--;
    
    if(front<=rear){
        front++;
    }else{
        if(front==MAX-1){
            front=0;
        }else{
            front++;
        }
    }
    if(count==0){
        front=-1;
        rear=-1;
}
}

//isempty function
bool isempty(){
    if(front==-1&&rear==-1||front==MAX){
        return true;
    }else{
        return false;
    }
}

//isfull function
bool isfull(){
    if(front==0&&rear==MAX-1||front==rear+1&&front!=MAX){
        return true;
    }else{
        return false;
    }
}

//print data
void print(){
    if(isempty()){
        printf("\nqueue is empty !");
        exit(1);
    }
    if(front<=rear){
        for(int i=front;i<=rear;i++){
            printf("\n%d",arr[i]);
        }
    }else{
        do{
            printf("\n%d",arr[front]);
            if(front==MAX-1){
                front=0;
            }else{
                front++;
            }
        }while(front!=rear+1);
    }
}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    dequeue();
    dequeue();
    dequeue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    enqueue(40);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    enqueue(90);
    dequeue();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(90); 

   
    print();
    return 0;
}