#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define length 1000000000

int busca_binaria(int *v, int target, int *qnt_tentativas)
{
  int min = 0;
  int max = length;

  while (min <= max)
  {
    (*qnt_tentativas)++;
    int middle = min + (max - min) / 2;
    int guess = v[middle];

    if (guess == target)
    {
      return middle;
    }
    else if (guess > target)
    {
      max = middle - 1;
    }
    else
    {
      min = middle + 1;
    }
  }
  return -1;
}

int main(int argc, char const *argv[])
{
  int *v = (int *)malloc(sizeof(int) * length);

  for (size_t i = 0; i < length; ++i)
  {
    v[i] = i + 100;
  }

  int target = 100;
  int qnt_tentativas = 0;

  int result = busca_binaria(v, target, &qnt_tentativas);

  if (result > 0)
    printf("O elemento está na posição: %d", result);

  printf("\nA quantidade de tentativas foi: %d", qnt_tentativas);

  return 0;
}
