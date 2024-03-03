#include <stdio.h>
#include <string.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head = NULL, *prev_link = NULL;
// create Doubly linked list
/* in this function user takes input for number of nodes and
according to this you creat a doubly linked list with data according to you*/

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
int main()
{

    creat_list();
    // printing list

    while (head)
    {
        printf("\n%d", head->data);
        head = head->next;
    }

    return 0;
}