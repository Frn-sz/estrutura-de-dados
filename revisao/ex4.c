#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int n;
  char string[20];
} line;

int main(int argc, char const *argv[])
{
  int f_digit;

  scanf("%d", &f_digit);

  line *vet = (line *)malloc(sizeof(line) * f_digit);

  for (size_t i = 0; i < f_digit; i++)
  {
    scanf("%d %19s\n", &vet[i].n, vet[i].string);
  }

  for (size_t i = 0; i < f_digit; i++)
  {
    printf("[%d,%.20s]\n", vet[i].n, vet[i].string);
  }

  free(vet);
  return EXIT_SUCCESS;
}
