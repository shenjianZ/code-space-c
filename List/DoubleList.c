//
// Created by shenjianZ on 2023/7/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct ListNode{
    E element;
    struct ListNode* prev;
    struct ListNode* next;
};

typedef struct ListNode* Node;

void initNode(Node node){
    node->next = node->prev = NULL;
}

bool insertList(Node head, E element, int index){
    if(head==NULL || index<1) return 0;
    Node front=head;
    while (index>1){
        front=front->next;
        index--;
    }
    head=front->next;
    Node newNode= malloc(sizeof (struct ListNode));
    newNode->element=element;
    if(front->next==NULL) {
        front->next=newNode;
        newNode->prev=front;
        newNode->next=NULL;
        return  1;
    }
    front->next=newNode;
    newNode->prev=front;
    newNode->next=head;
    head->prev=newNode;
    return 1;
}

bool deleteList(Node head,int index){
    if(head==NULL || index<1) return 0;
    Node front=head;
    while (index>1){
        front=front->next;
        index--;
    }
    head=front->next;
    Node temp=head;
    front->next=head->next;//等价于front->next=front->next->next
    head->next->prev=head->prev;//等价于head->next->prev=front;
    return 1;
}

E getList(Node head, int index) {
    if (head == NULL || index < 1)
        return 0;
    Node front = head;
    while (index > 1) {
        front = front->next;
        index--;
    }
    head = front->next;
    if (head != NULL) {
        int element = head->element;
        return element;
    }
    return 0;
}

int findList(Node head, E element){
    if(head==NULL) return 0;
    Node node=head->next;
    int i=1;
    while(node!=NULL){
        //while循环条件中的node!=NULL等价于node
        if(node->element==element)
            return i;
        node=node->next;
        i++;
    }
    return -1;
}

void forwardPrintList(Node head){
    Node node = head->next;
    while(node!=NULL){
        //while循环条件中的node!=NULL等价于node
        printf("%d->",node->element);
        node=node->next;
    }
}

void reversePrintList(Node head){
    Node node = head->next;
    while(node->next!=NULL)
        node=node->next;
    while(node!=head){
        //while循环条件中的node!=NULL等价于node
        printf("%d->",node->element);
        node=node->prev;
    }
}
int sizeList(Node head){
    int resSize=-1;
    Node node = head;
    while(node!=NULL){
        //while循环条件中的node!=NULL等价于node
        node=node->next;
        resSize++;
    }
    return resSize;
}
int main() {
    struct ListNode head;
    initNode(&head);
    for (int i = 1; i <= 10; ++i) {
        insertList(&head, i * 100, i);//尾插入
    }
    insertList(&head,0,5); //中间插入
    deleteList(&head,5); //删除第五个元素
    forwardPrintList(&head);//正向遍历打印
    printf("\n");
    reversePrintList(&head);//反向遍历打印
    printf("\n");
    printf("%d", sizeList(&head));
    printf("\n");
    printf("%d ", getList(&head,2));
    printf("\n");
    printf("%d ", findList(&head,200));

}