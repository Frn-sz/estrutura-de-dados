#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
  struct Tree *father;
  struct Tree *left;
  struct Tree *right;
  int key;
} Tree;

Tree *maximum(Tree *node)
{
  if (!node)
    return node;

  while (node->right)
    node = node->right;

  return node;
}

Tree *minimum(Tree *node)
{
  if (!node)
    return node;

  while (node->left)
    node = node->left;

  return node;
}

void in_order(Tree *node)
{
  if (!node)
    return;

  in_order(node->right);
  printf("%d\n", node->key);
  in_order(node->left);
}

void insert(Tree **tree, int key)
{
  Tree *y = NULL;
  Tree *x = *(tree);

  while (x)
  {
    y = x;

    if (key == x->key)
      return;
    else if (key < x->key)
      x = x->left;
    else
      x = x->right;
  }

  struct Tree *z = (struct Tree *)malloc(sizeof(struct Tree));
  z->key = key;
  z->father = y;
  z->left = NULL;
  z->right = NULL;

  if (!y)
    *tree = z;
  else if (z->key < y->key)
    y->left = z;
  else
    y->right = z;
}

Tree *search(Tree *node, int target)
{
  if (!node)
    return node;

  while (node && node->key != target)
    if (target < node->key)
      node = node->left;
    else
      node = node->right;

  if (node)
    printf("Achou: %d", node->key);
  else
    printf("Não achou: %d", target);

  return node;
}

Tree *tree_predecessor(Tree *root)
{
  if (!root)
    return root;

  if (root->left)
    return maximum(root->left);

  Tree *dummy = root->father;

  while (dummy && root == dummy->left)
  {
    root = dummy;
    dummy = dummy->father;
  }

  return dummy;
}

Tree *tree_successor(Tree *root)
{
  if (!root)
    return root;

  if (root->right)
    return minimum(root->right);

  Tree *dummy = root->father;

  while (dummy && root == dummy->right)
  {
    root = dummy;
    dummy = dummy->father;
  }

  return dummy;
}

void remove(Tree **tree, Tree *node)
{
  if (!node)
    return NULL;

  if (!node->left && !node->right)
  {
    if (node->father == NULL)
      *tree = NULL;
    else if (node->father->right == node)
      node->father->right = NULL;
    else
      node->father->left = NULL;

    free(node);
    return;
  }

  if (!node->left && node->right)
  {
    node->right->father = node->father;

    if (node->father)
    {
      if (node->father->right == node)
      {
        node->father->right = node->right;
      }
      else
      {
        node->father->left = node->right;
      }
    }
  }
}
int main(int argc, char const *argv[])
{
  Tree *tree = NULL;
  int v[] = {15, 10, 9, 120};

  for (size_t i = 0; i < 4; i++)
    insert(&tree, v[i]);

  Tree *dummy = NULL;

  dummy = search(tree, 2);

  if (!dummy)
    exit(1);

  dummy = tree_predecessor(dummy);

  if (!dummy)
    printf("Nenhum predecessor");

  printf("\nPredecessor:%d", dummy->key);

  return 0;
}