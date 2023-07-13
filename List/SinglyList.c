//
// Created by 15202 on 2023/7/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct ListNode{
    E element;
    struct ListNode * next;
};

typedef struct ListNode * Node;

void initList(Node node){
    node->next=NULL;
}

bool insertList(Node head, E element, int index){
    if(head==NULL || index<1) return 0;
    Node front;
    while (--index){
        front = head->next;
        head=head->next;
    }
    Node newNode= malloc(sizeof (struct ListNode));
    newNode->element=element;
    Node temp=front->next;
    front->next=newNode;
    newNode->next=temp;
    //newNode->next=front->next;
    //front->next=newNode;
    //也可以，与前30-32代码作用相同
    return 1;
}

bool deleteList(Node head, int index){
    if(head==NULL || index<1) return 0;
    Node front;
    //while循环执行index-1次,到达删除节点的前驱节点位置
    while(--index){
        front=head->next;
        head=head->next;
    }
    Node temp=front->next;
    front->next=front->next->next;
    free(temp);//释放被删除节点的内存
    return 1;
}

E * getList(Node head, int index){
    if(head==NULL || index<1) return 0;
    Node node;
    //do...while循环执行index次，到达删除节点的本身位置
    do{
        node=head->next;
        head=head->next;
    }while(--index);
    return &(node->element);
}

int findList(Node head, E element){
    if(head==NULL) return 0;
    Node node = NULL;
    int i=1;
    while(node==NULL){
        //while循环条件中的node==NULL等价于node
        if(node->element==element)
            return i;
        node=head;
        node=node->next;
        i++;
        if
    }
    return -1
}

int sizeList(Node head){
    int resSize=0;
    Node node = NULL;
    while(node==NULL){
        //while循环条件中的node==NULL等价于node
        node=head;
        node=node->next;
        resSize++;
    }
    return resSize;
}