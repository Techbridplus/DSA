#include<stdio.h>
#include<string.h>
#define size 100
int stack_arr[size];
int top=-1;
int isPrime(int num){
    if(num<=1) return 0;
    for(int i=2;i<num;i++){
        if(num%i==0)return 0;
    }
    return 1;
}
void prime_fact(){
    int m;
    printf("\nenter number : ");
    scanf("%d",&m);
    int n=m;
    for(int i=2;i<m;){
        if(isPrime(n)){
            stack_arr[++top]=n;
            return;
        }else if(isPrime(i)){
            if(n%i==0){
                stack_arr[++top]=i;
                n=n/i;
            }else{
                i++;
            }
        }else{
            i++;
        }
    }
    printf("\n\n\tNOW STACK IS CREATED...\n\n");
}
void print(){
    printf("\nprime factorisation in reverse is : ");
    for(int i=top;i>=0;i--){
        printf("\n%d",stack_arr[i]);
    }
}
int main(){
  prime_fact();
  print();
    return 0;
}