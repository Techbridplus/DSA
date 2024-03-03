#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *head = NULL, *tail = NULL;
//create list
void creat_list()
{
    int n;
    printf("enter number of nodes : ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("\nEMPTY LIST ! ");
        return;
    }
    int data;
    printf("\nenter data of node 1 : ");
    scanf("%d", &data);
    head = malloc(sizeof(struct node));
    head->data = data;
    head->link = NULL;
    tail = head;
    struct node *current = NULL;
    for (int i = 2; i <= n; i++)
    {
        current = malloc(sizeof(struct node));
        printf("\nenter data of node %d : ", i);
        scanf("%d", &data);
        current->data = data;
        current->link = NULL;
        tail->link = current;
        tail = current;
    }
    current = NULL;
    printf("\n\n\tLINKED LIST IS CREATED ...\n\n");
}

// reverse list
void reverse_list()
{
    struct node *temp = NULL, *temp2 = NULL;
    tail = head;
    while (head)
    {
        temp2 = head->link;
        head->link = temp;
        temp = head;
        head = temp2;
    }
    head = temp;
    printf("\n\n\t LIST IS REVERSED ...\n\n");
}

int main()
{

    creat_list();
    // after calling
    printf("\n\tPRINTING DATA OF LIST ...");
    struct node *ptr = head;
    while (ptr)
    {
        printf("\n\t%d", ptr->data);
        ptr = ptr->link;
    }
    // after reverse
    reverse_list();
    ptr = head;
    while (ptr)
    {
        printf("\n\t%d", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}