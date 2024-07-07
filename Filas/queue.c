#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *v;
    int start;
    int end;
    int length;
} Queue;

int is_empty(Queue *queue){
    return queue->start == queue->end;
}

int is_full(Queue *queue){
    return queue->end == queue->start - 1 || queue->start == 0 && queue->end == queue->length - 1;
}

void enqueue(Queue *queue, int n){
    if(is_full(queue)){
        printf("Pilha cheia");
        exit(1);
    }

    queue->v[queue->end] = n;

    if(queue->end == queue->length -1){
        queue->end = 0;
    }else{
        queue->end++;
    }
}


int dequeue(Queue *queue){

    if(is_empty(queue)){
        printf("Pilha vazia");
        exit(1);
    }

    int temp = queue->v[queue->start];

    if(queue->start == queue->length - 1){
        queue->start = 0;
    }else{
        queue->start++;
    }

    return temp;
}

int main(){
    Queue queue = {(int*) malloc(sizeof (int) * 21),0,0, };

    enqueue(&queue,5);
    enqueue(&queue,10);
    enqueue(&queue,20);

    printf("%d\n", dequeue(&queue));
    printf("%d\n", dequeue(&queue));
    printf("%d\n", dequeue(&queue));
    printf("%d\n", dequeue(&queue));

    free(queue.v);
}
