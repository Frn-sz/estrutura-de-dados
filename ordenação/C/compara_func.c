#include <stdio.h>
#include <stdlib.h>
int compara1(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

int compara2(const void *a, const void *b)
{
  return *(int *)b - *(int *)a;
}

int compara3(const void *a, const void *b)
{
  int ia = *(int *)a;
  int ib = *(int *)b;

  if (ia % 2 != 0 && ib % 2 == 0)
  {
    return -1;
  }
  else if (ia % 2 == 0 && ib % 2 != 0)
  {
    return 1;
  }
  else
  {
    if (ia > ib)
    {
      return 1;
    }
    else
    {
      return -1;
    }
  }
}

int compara4(const void *a, const void *b)
{
  int ia = *(int *)a;
  int ib = *(int *)b;

  if (ia > 0 && ib < 0)
  {
    return -1;
  }
  else if (ia < 0 && ib > 0)
  {
    return 1;
  }
  else if (ia >= 0 && ib >= 0)
  {
    if (ia > ib)
    {
      return 1;
    }
    else if (ib > ia)
    {
      return -1;
    }
  }
  else
  {
    if (ia > ib)
    {
      return -1;
    }
    else if (ib > ia)
    {
      return 1;
    }
  }
}

int compara5(const void *a, const void *b)
{
  int ia = *(int *)a;
  int ib = *(int *)b;

  if (abs(ia) > abs(ib))
  {
    return 1;
  }
  else if (abs(ib) > abs(ia))
  {
    return -1;
  }

  if (ia < 0 && ib >= 0)
  {
    return 1;
  }
  else if (ib < 0 && ia >= 0)
  {
    return -1;
  }

  return 0;
}
int main(int argc, char const *argv[])
{
  int v[6] = {2, -3, 1, 3, -1, -2};

  for (int i = 0; i < 6; ++i)
    printf("%d\n", v[i]);

  qsort(v, 6, sizeof(int), &compara1);

  printf("Compara 1\n");
  for (int i = 0; i < 6; ++i)
    printf("%d\n", v[i]);

  qsort(v, 6, sizeof(int), &compara2);

  printf("Compara 2\n");
  for (int i = 0; i < 6; ++i)
    printf("%d\n", v[i]);

  qsort(v, 6, sizeof(int), &compara3);

  printf("Compara 3\n");
  for (int i = 0; i < 6; ++i)
    printf("%d\n", v[i]);

  qsort(v, 6, sizeof(int), &compara4);

  printf("Compara 4\n");
  for (int i = 0; i < 6; ++i)
    printf("%d\n", v[i]);

  qsort(v, 6, sizeof(int), &compara5);

  printf("Compara 5\n");
  for (int i = 0; i < 6; ++i)
    printf("%d\n", v[i]);
  return 0;
}
