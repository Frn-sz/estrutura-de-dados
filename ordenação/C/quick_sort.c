#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define len 10000000

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void insertion_sort(int *v, int start, int end) {
  for (size_t i = start; i < end; ++i)
    for (size_t j = i; j > 0 && v[j - 1] > v[j]; --j)
      swap(&v[j], &v[j - 1]);
}

int chooseMedian(int *v, int a, int b, int c) {
  if ((v[a] < v[b] && v[b] < v[c]) || (v[c] < v[b] && v[b] < v[a]))
    return b;
  else if ((v[b] < v[a] && v[a] < v[c]) || (v[c] < v[a] && v[a] < v[b]))
    return a;
  else
    return c;
}

void quick_sort(int *v, int start, int end) {
  if (start >= end)
    return;

  if (end - start <= 10) {
    insertion_sort(v, start, end);
    return;
  }

  int p = chooseMedian(v, start, (start + end) / 2, end);
  swap(&v[p], &v[end]);

  int j = start;

  for (int i = start; i <= end; ++i)
    if (v[i] <= v[end]) {
      swap(&v[i], &v[j]);
      ++j;
    }

  quick_sort(v, start, j - 2);
  quick_sort(v, j, end);
}

int main(int argc, char const *argv[]) {
  int *v = (int *)malloc(sizeof(int) * len);

  for (int i = 0; i < len; ++i)
    v[i] = rand() % len;

  clock_t begin = clock();
  quick_sort(v, 0, len - 1);
  clock_t end = clock();

  double time = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("Tempo Quick: %0.2fs\n", time);

  free(v);
  return 0;
}
