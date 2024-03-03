#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5
int arr[MAX];
bool isfull();
bool isempty();
int front = -1, rear = -1;
// push function
void enqueue(int data)
{
    if(front==-1){
        front++;
        rear++;
        arr[rear]=data;
    }else if(!isfull()){
        rear++;
        arr[rear]=data;
    }else{
        printf("\nqueue is full !");
        exit(1);
    }
}

// pop function
void dequeue()
{
    if (isempty())
    {   front=-1;
        rear=-1;
        printf("\nsorry we can't delete => queue is empty");
        exit(1);
    }
    front++;
    if(front>rear){
        front=-1;
        rear=-1;
    }

}

//isfull
bool isfull(){
    if(rear==MAX-1){
        return true;
    }else{
        return false;
    }
}
//isEMPTY
bool isempty(){
    if(front==-1||front>rear){
        return true;
    }else{
        return false;
    }
}

// print data
void print()
{
    if(front == -1|| front== rear + 1){
        printf("\nqueue is EMPTY !");
        exit(1);
    }
    do{
        printf("\n%d",arr[front]);
    }while(front++!=rear&&front<rear+1);
}
int main()
{
   
    enqueue(67);
    print();
    return 0;
}