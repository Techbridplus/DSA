#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    if (n <= 0)
    {
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
        prev_link->next = current;
        prev_link = current;
    }
    printf("\n\n\tCREATED LIST...\n\n\n");
}
// reverse list
void reverse_list()
{
    struct node*temp=NULL;
    while(head){
        temp=head->next;
        head->next=head->prev;
        head->prev=temp;
        head=head->prev;
    }
    head=prev_link;
    temp=NULL;
    printf("\n\n\tLIST IS REVERSED...\n\n\n");

}
void print(){
    struct node* ptr=head;
    while(ptr){
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
creat_list();
//printing list
print();
// reverse list
reverse_list();
print();

    return 0;
}