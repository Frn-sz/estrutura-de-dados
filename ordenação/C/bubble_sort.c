#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define size_v 100000

void swap(int *x, int *y)
{
  int temp = *x;
  *y = *x;
  *x = temp;
}

void bubble_sort(int *v, int size)
{
  int limit = 0;
  int temp = 0;

  for (size_t i = limit; i < size; ++i)
  {
    for (size_t j = limit + 1; j < size; ++j)
    {
      if (v[i] > v[j])
      {
        temp = v[j];
        v[j] = v[i];
        v[i] = temp;
      }
    }
    limit++;
  }
}

void insertion_sort(int *v, int size)
{
  int temp = 0;
  for (size_t i = 0; i < size; ++i)
    for (size_t j = i; j > 0 && v[j - 1] > v[j]; --j)
    {
      temp = v[j - 1];
      v[j - 1] = v[j];
      v[j] = temp;
    }
}
int main(int argc, char const *argv[])
{
  int *v = (int *)malloc(sizeof(int) * size_v);
  int *x = (int *)malloc(sizeof(int) * size_v);

  srand(time(NULL));

  for (size_t i = 0; i < size_v; ++i)
  {
    v[i] = rand() % 10000;
    x[i] = v[i];
  }
  clock_t begin = clock();
  bubble_sort(v, size_v);
  clock_t end = clock();

  double time = (double)(end - begin) / CLOCKS_PER_SEC;
  ;
  printf("Tempo Bubble: %0.2f\n", time);

  begin = clock();
  insertion_sort(x, size_v);
  end = clock();

  time = (double)(end - begin) / CLOCKS_PER_SEC;
  ;
  printf("Tempo Insertion: %0.2f\n", time);

  for (int i = 0; i < size_v; i++)
    return 0;
}
