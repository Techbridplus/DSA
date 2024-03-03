#include<stdio.h>
#include<string.h>
#define size 100
int stack[size];
int top=-1;

void deci_to_bin(){
    int n;
    printf("\nenter number : ");
    scanf("%d",&n);
    while(n){
        stack[++top]=n%2;
        n/=2;
    }
    printf("\n\n\tBINARY NUMBER IS CREATED...\n\n");

}
void print(){
    printf("\n0b");
    for(int i=top;i>=0;i--){
        printf("%d",stack[i]);
    }
}
int main(){
    deci_to_bin();
    print();
    return 0;
}