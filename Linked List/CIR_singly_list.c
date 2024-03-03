#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*tail=NULL;

// create circular singly linked list
void create_list(){
    int n;
    printf("\nenter no of nodes : ");
    scanf("%d",&n);
    if(n<=0){
        printf("\nEMPTY LIST...");
        return;
    }
    int data;
    struct node* temp=malloc(sizeof(struct node));
    tail=temp;
    printf("\nenter data of node 1 : ");
    scanf("%d",&data);
    tail->data=data;
    tail->next=NULL;
    for(int i=2;i<=n;i++){
        printf("\nenter data of node %d : ",i);
        scanf("%d",&data);
        struct node* current=malloc(sizeof(struct node));
        current->data=data;
        current->next=NULL;
        tail->next=current;
        tail=current;
    }
    tail->next=temp;
    temp=NULL;
    printf("\n\n\tCIRCULAR SINGLY LIST IS CREATED ...\n\n\n");

}
// add at beginning
void add_at_beg(int data){
    struct node*current=malloc(sizeof(struct node));
    current->data=data;
    current->next=tail->next;
    tail->next=current;
}
// add at end
void add_at_end(int data){
    struct node*current=malloc(sizeof(struct node));
    current->data=data;
    current->next=tail->next;
    tail->next=current;
    tail=current;
    
}
void add_at_any(int data){
    int pos;
    printf("\nenter position where to add : ");
    scanf("%d",&pos);
    if(pos<=0){
        printf("\nPOSTION NOT EXIST !!!");
        return;
    }
    if(pos==1){
        add_at_beg(data);
        return;
    }else{
    int count=1;
    struct node*current=tail->next;
    while((pos-1)!=count){
        current=current->next;
        count++;
    }
    if(current->next==tail){
        add_at_end(data);
        return;
    }
    struct node*temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=current->next;
    current->next=temp;
    }
}
// print data of list
void print(){
    printf("\n\n\tDATA OF LIST...\n\n\n");
    struct node* ptr=tail->next;
    do{
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }while(ptr!=tail->next);
}
int main(){
    create_list();
    //printf("\ncalling for add at  beginning...\n");
    //add_at_beg(800);
    //printf("\ncalling for add at end...\n");
    //add_at_end(1000);
    printf("\ncalling for add at any position...\n");
    add_at_any(1000);
    printf("\ncalling for printing...\n");
    print();
    
    return 0;
}