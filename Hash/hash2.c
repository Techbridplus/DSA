#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct hash{
    int key;
    int value;
    struct hash*next;
}*head=NULL;

// This function is used to match key if key match increase corresponding value by 1;
void match(int key){
    int ret=0;
    if(head==NULL){
        printf("\nEMPTY...");
    }
    struct hash*ptr=head;

    while(ptr){
        if(ptr->key==key){
            printf("\npresent");
            return;
        }
            ptr=ptr->next;
    }
    struct hash*node=malloc(sizeof(struct hash));
    node->key=key;
    node->next=head;
    head=node;
    printf("\nnot present");
}
int main(){
    int arr[6]={2,4,3,7,3,2};
  for(int i=0;i<6;i++){
    match(arr[i]);
  }
    
    
    return 0;
}