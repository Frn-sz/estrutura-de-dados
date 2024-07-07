#include <stdio.h>
#include <stdlib.h>
#define length 5

int busca_sequencial(int *v, int target)
{
  for (int i = 0; i < length; i++)
  {
    if (v[i] == target)
      return i;
  }
  return -1;
}
int main(int argc, char const *argv[])
{
  int v[] = {1, 2, 3, 4, 10};
  int target = 10;

  int result = busca_sequencial(v, target);

  if (result > 0)
    printf("O elemento está na posição: %d", result);
  return 0;
}
