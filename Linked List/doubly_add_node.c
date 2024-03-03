#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
}*head=NULL,*prev_link=NULL;
// Add at end
void insert_at_end(int dta){
    struct node* current=malloc(sizeof(struct node));
    current->prev=prev_link;
    current->data=dta;
    current->next=NULL;
    prev_link->next=current;
    prev_link=current;
}
// Add at beginning
void insert_at_beg(int dta){
    struct node* current=malloc(sizeof(struct node));
    current->prev=NULL;
    current->data=dta;
    current->next=head;
    head->prev=current;
    head=current;

}
// insert at any position
void insert_at_any(int pos,int dta){
    int count=1;
     if(pos==1){
        insert_at_beg(dta);
     }else{
        struct node* new_node=malloc(sizeof(struct node));
        new_node->data=dta;
        struct node*current=head,*temp=NULL;
        while((pos-1)!=count){
            current=current->next;
            count++;
        }
        temp=current->next;
        current->next=new_node;
        new_node->prev=current;
        new_node->next=temp;
        temp->prev=new_node;
     }
}

int main(){
  head=malloc(sizeof(struct node));
  head->prev=NULL;
  head->data=10;
  head->next=NULL;
  prev_link=head;
  insert_at_end(20);
  insert_at_end(30);
  insert_at_end(40);
  insert_at_beg(100);
  insert_at_any(6,200);
  // printing data
  struct node*ptr=head;
  while(ptr){
    printf("\n%d",ptr->data);
    ptr=ptr->next;
  }
  ptr=prev_link;
 // while (ptr)
 // {
 //   printf("\n%d",ptr->data);
 //   ptr=ptr->prev;
 // }
 // 
   return 0;
}