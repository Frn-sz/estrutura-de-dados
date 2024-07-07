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
  FILE *fp = fopen("arq2.txt", "r");

  if (!fp)
  {
    perror("ERROR");
    exit(1);
  }

  fscanf(fp, "%d", &f_digit);

  line *vet = (line *)malloc(sizeof(line) * f_digit);

  if(!vet){
    perror("ERROR");
    exit(EXIT_FAILURE);
  }
  for (size_t i = 0; i < f_digit; i++)
  {
    fscanf(fp, "%d %19s\n", &vet[i].n, vet[i].string);
  }

  fclose(fp);

  for (size_t i = 0; i < f_digit; i++)
  {
    printf("[%d,%.20s]\n", vet[i].n, vet[i].string);
  }

  free(vet);
  return EXIT_SUCCESS;
}
