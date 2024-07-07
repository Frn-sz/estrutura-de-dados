#include <stdio.h>
#include <stdlib.h>

struct Node
{
  struct Node *prev;
  struct Node *next;
  int key;
};

typedef struct Node Node;

struct List
{
  Node *start;
  Node *end;
  int lenght;
};

typedef struct List List;

void init(List *list)
{
  list->start = NULL;
  list->end = NULL;
  list->lenght = 0;
}

void push(List *list, int key)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->key = key;
  new_node->next = list->start;
  new_node->prev = NULL;
  if (list->lenght > 0)
    list->start->prev = new_node;
  list->start = new_node;

  if (list->lenght == 0)
    list->end = new_node;

  list->lenght++;
}

void pop(List *list)
{
  if (list->lenght == 0)
    return;
  else
  {
    Node *temp = list->start;
    if (list->lenght == 1)
      list->start = NULL;
    else
    {
      list->start = list->start->next;
      list->start->prev = NULL;
    }
    printf("%d\n", temp->key);
    free(temp);
    (list->lenght)--;
  }
}
void print(List *list)
{
  Node *node = list->start;

  while (node)
  {
    printf("%d\n", node->key);
    node = node->next;
  }
}

void print_end(List *list)
{
  Node *node = list->end;

  while (node)
  {
    printf("%d\n", node->key);
    node = node->prev;
  }
}

int main(int argc, char const *argv[])
{
  List l1 = {NULL, NULL, 0};
  List *l2 = (List *)malloc(sizeof(List));
  init(l2);

  for (size_t i = 0; i < 50; ++i)
    push(l2, i);
  
  printf("Ordem normal:\n");
  print(l2);

  printf("Ordem inversa:\n");
  print_end(l2);

  printf("\nRetirados:\n");
  
  for (size_t i = 0; i < 20; ++i)
    pop(l2);

  return 0;
}
