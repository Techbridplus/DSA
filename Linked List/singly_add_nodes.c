#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
};

// Function used to add a node at the end of the linked list
struct node *add_at_end(struct node *ptr, int dta)
{
  struct node *current = malloc(sizeof(struct node));
  current->data = dta;
  current->link = NULL;
  ptr->link = current;
  ptr = ptr->link;
  return ptr;
}

// Function used to add a node at the beginning of the linked list
struct node *add_at_beg(struct node *gtr, int dta)
{
  struct node *current = malloc(sizeof(struct node));
  current->data = dta;
  current->link = gtr;
  return current;
}

// Function used to add a node at any position in the linked list
void at_any_pos(struct node **head, int pos, int dta)
{
  struct node *current = malloc(sizeof(struct node));
  current->data = dta;
  current->link = NULL;

  if (pos == 1)
  {
    *head = add_at_beg(*head, dta);
  }
  else
  {
    struct node *temp = *head;
    int count = 1;

    while (temp != NULL)
    {
      if (count != pos - 1)
      {
        temp = temp->link;
        count++;
      }
      else
      {
        current->link = temp->link;
        temp->link = current;
        break;
      }
    }
  }
}

int main()
{
  struct node *head = malloc(sizeof(struct node));
  head->data = 20;
  head->link = NULL;
  struct node *ptr = head;

  // Add nodes at the end
  ptr = add_at_end(ptr, 30);
  ptr = add_at_end(ptr, 40);
  ptr = head;
  // Add node at the beginning
  ptr = add_at_beg(ptr, 10);
  head = ptr;

  // Add node at any position
  at_any_pos(&head, 5, 100);

  ptr = head;

  // Print the linked list
  while (ptr != NULL)
  {
    printf("\n%d", ptr->data);
    ptr = ptr->link;
  }

  return 0;
}
