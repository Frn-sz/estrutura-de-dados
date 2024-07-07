#include <stdio.h>
#include <stdlib.h>

struct Pessoa
{
  char *name;
  int priority;
};

struct Node
{
  struct Pessoa *pessoa;
  struct Node *next;
};

struct List
{
  struct Node *start;
  int length;
};

typedef struct Pessoa Pessoa;
typedef struct Node Node;
typedef struct List List;

Pessoa *make_pessoa(char *name, int priority)
{
  Pessoa *pessoa = (Pessoa *)malloc(sizeof(pessoa));
  if (pessoa)
  {
    pessoa->name = name;
    pessoa->priority = priority;
    return pessoa;
  }
  exit(1);
}

void push(List *list, Pessoa *pessoa)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (list->length == 0 || pessoa->priority > list->start->pessoa->priority)
  {
    new_node->next = list->start;
    list->start = new_node;
  }
  else
  {
    Node *temp = list->start;

    while (temp->next && pessoa->priority <= temp->next->pessoa->priority)
      temp = temp->next;
    new_node->next = temp->next;
    temp->next = new_node;
  }
  new_node->pessoa = pessoa;
  (list->length)++;
}
void pop(List *list)
{
  if (!list->length)
    return;

  Node *node = list->start;
  list->start = node->next;
  free(node->pessoa);
  free(node);
  (list->length)--;
}
void print_list(List *list)
{
  Node *node = list->start;
  while (node)
  {
    printf("\nNome: %s\nPrioridade: %d", node->pessoa->name, node->pessoa->priority);
    node = node->next;
  }
}

int main(int argc, char const *argv[])
{
  List *list = (List *)malloc(sizeof(list));
  list->start = NULL;
  list->length = 0;

  char *names[] = {"Fernando", "Cilmara", "Rafael"};
  int priority[] = {2, 1, 0};
  for (size_t i = 0; i < 3; ++i)
  {
    push(list, make_pessoa(names[i], priority[i]));
  }
  print_list(list);
  printf("\nInseridos!");
  while (list->length - 2 )
    pop(list);
  printf("\nRemovidos!");

  print_list(list);
  return 0;
}
