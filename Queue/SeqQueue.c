//
// Created by shenjianZ on 2023/7/19.
//
// this is a Circular Queue.  循环队列

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
typedef int E;

struct SeqQueue{
    E * array;
    int capacity;   //数组容量
    int tail,front;  //队尾、队首指针
};

typedef struct SeqQueue * Queue;

bool initQueue(Queue queue){
    queue->array= malloc(sizeof (E)*10);
    if(queue->array==NULL) return 0;
    queue->capacity = 10;
    queue->tail=queue->front=0;
    return 1;
}

bool offerQueue(Queue queue,E element){
    if((queue->tail+1) % queue->capacity==queue->front)
        return 0;
    queue->array[queue->tail]=element;
    queue->tail=(queue->tail+1) % queue->capacity;
    return 1;
}

E pollQueue(Queue queue){
     queue->front=(queue->front+1)%queue->capacity;
    return queue->array[queue->front-1];
}

E peekQueue(Queue queue){
    return queue->array[queue->front];

}
void printQueue(Queue queue){
    int index=queue->front;
    printf("<<< ");
    do{
        printf("%d,",queue->array[index]);
        index=(index+1) % queue->capacity;
    }while(index!=queue->tail);
    printf("<<<\n");
}

bool isEmpty(Queue queue){
    return queue->front==queue->tail;
}

int main(){
    struct SeqQueue queue;
    initQueue(&queue);
    for (int i = 0; i < 10; ++i) {
        offerQueue(&queue, i * 100);
    }
    printQueue(&queue);
    printf("%d\n", peekQueue(&queue));
    while (!isEmpty(&queue)) {
        printf("%d ", pollQueue(&queue));
    }

}