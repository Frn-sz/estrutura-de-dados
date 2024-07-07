#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

  int f_digit;
  fscanf(stdin, "%d", &f_digit);

  int *buffer = (int *)malloc(sizeof(int) * f_digit);
  
  for (size_t i = 0; i < f_digit; i++)
  {
    fscanf(stdin, "%d", &buffer[i]);
  }

  for (size_t i = 0; i < f_digit; i++)
  {
    printf("%d\n", buffer[i]);
  }

  return 0;
}
