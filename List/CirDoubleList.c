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
struct CirDoubleList{
    struct ListNode* head;
    struct ListNode* tail;
    int size;
};
typedef struct ListNode* Node;

typedef struct CirDoubleList* List;

void initList(List list){
    list->head= malloc(sizeof (struct ListNode));
    list->tail= malloc(sizeof (struct ListNode));
    list->head->next = list->head->prev=NULL;
    list->tail->next = list->tail->prev=NULL;
    list->size=0;
}

/*
 * 索引的合法插入范围 [1,size+1]，即包含了尾插入
 */
bool insertList(List list, E element, int index){
    Node head=list->head;
    if(head==NULL || index<1) return 0;
    Node oldHead=head;
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
        newNode->next=oldHead;
        oldHead->prev=newNode;
        list->size++;
        return  1;
    }
    front->next=newNode;
    newNode->prev=front;
    newNode->next=head;
    head->prev=newNode;
    list->size++;
    return 1;
}

bool deleteList(List list,int index){
    Node head=list->head;
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
    list->size--;
    return 1;
}

E getList(List list, int index) {
    Node head=list->head;
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

int findList(List list, E element){
    Node head=list->head;
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

void forwardPrintList(List list){
    Node head=list->head;
    Node node = head->next;
    while(node!=head){
        //while循环条件中的node!=NULL等价于node
        printf("%d->",node->element);
        node=node->next;
    }
}

void reversePrintList(List list){
    Node head=list->head;
    Node node = head->next;
    while(node->next!=NULL)
        node=node->next;
    while(node!=head){
        //while循环条件中的node!=NULL等价于node
        printf("%d->",node->element);
        node=node->prev;
    }
}
int sizeList(List list){
    Node head=list->head;
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
    struct CirDoubleList cirDoubleList;
    initList(&cirDoubleList);
    for (int i = 1; i <= 10; ++i) {
        insertList(&cirDoubleList, i * 100, i);//尾插入
    }
    insertList(&cirDoubleList,0,5); //中间插入
    deleteList(&cirDoubleList,5); //删除第五个元素
    forwardPrintList(&cirDoubleList);//正向遍历打印
    printf("\n");
    reversePrintList(&cirDoubleList);//反向遍历打印
    printf("\n");
    printf("%d", sizeList(&cirDoubleList));
    printf("\n");
    printf("%d ", getList(&cirDoubleList,2));
    printf("\n");
    printf("%d ", findList(&cirDoubleList,200));

}