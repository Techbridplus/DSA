#include<stdio.h>
#include<string.h>
#define size 5
int top=-1;
int stack_arr[size];
int isFull();
int isEmpty();
//...
void push(int data){
if(top==size-1){
    printf("\nstack overflow");
    return;
}    
top++;
stack_arr[top]=data;

}
//...
int pop(){
    if(top==-1){
        printf("\nstack underflow");
        return;
    }
    int value=stack_arr[top];
    top--;
    return value;
}
//... 
int main(){
    
    return 0;
}
//functions
int isFull(){
    if(top==size-1){
        return 1;
    }else{
        return 0;
    }
}
int isEmpty(){
     if(top==-1){
        return 1;
    }
    return 0;
}