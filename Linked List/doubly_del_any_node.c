#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head = NULL, *prev_link = NULL;
// creat list
void creat_list()
{
    int n;
    printf("enter number of nodes : ");
    scanf("%d", &n);
    if (n == 0){
    printf("\nEMPTY NODES");
            return;
    }
    int a;
    head = malloc(sizeof(struct node));
    printf("\nenter the data for node 1 : ");
    scanf("%d", &a);
    head->prev = NULL;
    head->data = a;
    head->next = NULL;
    prev_link = head;
    for (int i = 2; i <= n; i++)
    {
        printf("\nenter the data for node %d : ", i);
        scanf("%d", &a);
        struct node *current = malloc(sizeof(struct node));
        current->data = a;
        current->prev = prev_link;
        current->next = NULL;
        prev_link->next=current;
        prev_link = current;
    }
}
// delete first node
void del_first_node(){
    struct node* temp=head;
    head=head->next;
    head->prev=NULL;

    free(temp);
    temp=NULL;

}
// delete any node
void del_any_node(int pos){
    if(pos==1){
        del_first_node();
    }else{
        struct node* current=head,*temp=NULL;
        int count=1;
        while((pos-1)!=count){
            current=current->next;
            count++;
        }
        if(current->next->next==NULL){
            free(current->next);
            current->next=NULL;
            return;
        }
        temp=current->next;
        current->next=current->next->next;
        current->next->next->prev=current;
        free(temp);
        temp=NULL;

    }
}

int main(){
    
    creat_list();
    // printing list
    printf("\ncreated list is : \n\t");
    struct node* ptr=head;
    while (ptr)
    {
        printf("\n\t%d", ptr->data);
        ptr = ptr->next;
    }
    // after deleting list
    int n;
    printf("\nenter position of node which you want to delete : ");
    scanf("%d",&n);
    del_any_node(n);
    printf("\n after deleting node ...");
    ptr=head;
    while (ptr)
    {
        printf("\n\t%d", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}