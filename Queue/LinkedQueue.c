//
// Created by shenjianZ on 2023/7/19.
//

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef int E;

struct LinkedNode{
    E element;
    struct LinkedNode * next;

};

typedef struct LinkedNode * Node;

struct LinkedQueue {
    Node front;
    Node tail;
};

typedef struct LinkedQueue * Queue;

void printQueue(Queue queue);
bool initQueue(Queue queue){
    Node node= malloc(sizeof (struct LinkedNode));
    if(node==NULL) return 0;
    node->next=NULL;
    queue->front=queue->tail=node;   //一开始两个指针都是指向头结点的，表示队列为空
    return 1;
}

bool offerQueue(Queue queue,E element){
    Node node = malloc(sizeof (struct LinkedNode));
    if(node==NULL) return 0;
    node->element=element;
    queue->tail->next=node;
    node->next=NULL;
    queue->tail = node; // 将尾指针指向新节点
    return 1;
}

E pollQueue(Queue queue){
    if (queue->front == queue->tail)
        return -1; // 队列为空
    E element = queue->front->next->element;
    Node temp = queue->front->next;
    queue->front->next = temp->next;
    free(temp);
    if (queue->front->next == NULL)
        queue->tail = queue->front; // 当队列中只剩下一个元素时，更新尾指针
    return element;
}

E peekQueue(Queue queue){
    return queue->front->next->element;

}

void printQueue(Queue queue) {
    printf("<<< ");
    Node node = queue->front->next;
    while (node != NULL) {    //注意不能直接判空，因为前面我们没考虑，也就没将新结点next设定为NULL
        printf("%d ", node->element);
        node = node->next;
    }
    printf("<<<\n");

}
int main(){
    struct LinkedQueue queue ;
    initQueue(&queue);
    for (int i = 0; i < 7; ++i) {
        offerQueue(&queue, i*100);
    }
    printf("%d\n", peekQueue(&queue));
    printf("%d\n", pollQueue(&queue));
    printQueue(&queue);
}


