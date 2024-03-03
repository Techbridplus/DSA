#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *link;
};
// function used to add node at end of the linked list
struct node *add_at_end(struct node *ptr, int dta)
{
  struct node *current = malloc(sizeof(struct node));
  current->data = dta;
  current->link = NULL;
  ptr->link = current;
  ptr = ptr->link;
  return ptr;
}
// delete first node
void del_first(struct node **head)
{
  struct node *temp = *head;
  *head = (*head)->link;
  free(temp);
  temp = NULL;
}
// delete last node
void del_last(struct node *head)
{
  struct node *temp1 = head;
  struct node *temp2 = head;
  while (temp1->link->link != NULL)
  {
    temp1 = temp1->link;
  }
  free(temp1->link);
  temp1->link = NULL;
}
// delete any node
void del_any_node(struct node **head, int pos)
{
  int count = 1;
  struct node *temp = NULL;
  if (pos == 1)
  {
    del_first((head));
  }
  else
  {
    while ((pos - 1) != count)
    {
      *head = (*head)->link;
      count++;
    }
    temp = (*head)->link->link;
    free((*head)->link);
    (*head)->link = temp;
  }
}
int main()
{
  struct node *head = malloc(sizeof(struct node));
  head->data = 10;
  head->link = NULL;
  struct node *ptr = head;
  // add at end
  ptr = add_at_end(ptr, 20);
  ptr = add_at_end(ptr, 30);
  ptr = add_at_end(ptr, 40);
  ptr = head;
  // calling function
  // del_first(&ptr);
  // del_last(ptr);
  // del_any_node(&ptr,2);

  // priting linked list
  while (ptr != NULL)
  {
    printf("\n%d", ptr->data);
    ptr = ptr->link;
  }
  return 0;
}
