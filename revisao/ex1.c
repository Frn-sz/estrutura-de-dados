#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  FILE *fp = fopen("arq.txt", "r");

  if (!fp)
  {
    perror("ERRO");
    exit(1);
  }
  char str[1];

  int digit;

  fscanf(fp, "%d", &digit);

  int *vet = (int *)malloc(sizeof(int) * digit);

  if (!vet)
  {
    perror("ERROR");
    exit(1);
  }

  for (size_t i = 0; i < digit; i++)
  {
    fscanf(fp, "%d\n", &vet[i]);
  }

  fclose(fp);

  printf("{");

  for (int z = 0; z < digit; z++)
  {
    if (z != digit - 1)
    {
      printf("%d,", vet[z]);
    }
    else
    {
      printf("%d", vet[z]);
    }
  }
  printf("}");
  free(vet);

  return EXIT_SUCCESS;
}
