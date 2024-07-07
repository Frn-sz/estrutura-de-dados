#include <stdio.h>
#include <stdlib.h>
#define tam 30

int top = -1;

inline int verify_overflow(){
  if(top == tam - 1){
    return 1;
  }else{
    return 0;
  }
}

inline int verify_underflow(){
  if(top == -1)
    return 1;
  return 0;
}

void push(int v[tam],int var){
  if(!verify_overflow()){
    v[++top] = var;
  }else{
    printf("A pilha está cheia\n");
  }  
}

int pop(int v[tam]){
  if(!verify_underflow()){
    return v[top--];
  }else{
    printf("A pilha está vazia\n");
  }
}

int main(int argc, char *argv[])
{
  int v[tam];
  int action = 0;
  int n = 0;

  while(1){
  printf("O que você deseja fazer?\n1-Empilhar item\n2-Retirar item\n3-Ver pilha\n4-Sair\n");
  scanf("%d",&action);
  
  switch(action){
    case 1:
      printf("Digite o item desejado\n");
      scanf("%d",&n);
      push(v,n);
      break;
    case 2:
      printf("%d\n", pop(v));
      break;
    case 3:
      for(int i = top;i >= 0;i--){
        printf("%d\n",v[i]);
      }
      break;
    case 4:
      printf("Até mais!\n");
      return EXIT_SUCCESS;
    }
  }
  return EXIT_SUCCESS;
}
