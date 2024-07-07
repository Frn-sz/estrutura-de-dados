#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1;



struct Node
{
  int key;
  struct Node *next;
};

int is_empty(struct Node **head)
{
  if (*head == NULL)
  {
    return TRUE;
  }

  return FALSE;
}
void *push(struct Node **head, int key)
{
  struct Node *new_node = malloc(sizeof(struct Node));

  if (new_node == NULL)
  {
    return NULL;
  }

  new_node->next = *head;
  new_node->key = key;
  *head = new_node;

  return new_node;
}

struct Node *pop(struct Node **head)
{
  if (is_empty(head))
  {
    printf("Lista vazia!");
    exit(1);
  }

  struct Node *temp = *head;
  *head = (*head)->next;

  return temp;
}
void print_list(struct Node **head)
{

  if (is_empty(head))
  {
    printf("Lista vazia!");
    return;
  }
  struct Node *temp_ptr = *head;

  while (temp_ptr)
  {
    printf("%d\n", temp_ptr->key);
    temp_ptr = temp_ptr->next;
  }
}
int main(int argc, char const *argv[])
{
  struct Node *head = NULL;

  push(&head, 1);
  push(&head, 2);
  push(&head, 3);

  struct Node *node = pop(&head);
  printf("Retirado: %d\n", node->key);
  free(node);

  print_list(&head);

  printf("OK");
  return 0;
}
