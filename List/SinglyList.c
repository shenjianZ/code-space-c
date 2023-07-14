//
// Created by shenjianZ on 2023/7/14.
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
        newNode->next=NULL;
        return 1;
    }
    //Node temp=front->next;
    //front->next=newNode;
    //newNode->next=temp;
    front->next=newNode;
    newNode->next=head;

    //也可以，与前30-32代码作用相同
    return 1;
}

bool deleteList(Node head, int index){
    if(head==NULL || index<1) return 0;
    Node front=head;
    while (index>1){
        front=front->next;
        index--;
    }
    head=front->next;
    if(head==NULL){
        front->next=NULL;
        return 1;
    }
    Node temp=head;
    front->next=front->next->next;
    free(temp);//释放被删除节点的内存
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

int sizeList(Node head){
    //因为头结点没有存储数据
    int resSize=-1;
    Node node = head;
    while(node!=NULL){
        //while循环条件中的node!=NULL等价于node
        node=node->next;
        resSize++;
    }
    return resSize;
}

void printList(Node head){
    Node node = head->next;
    while(node!=NULL){
        //while循环条件中的node!=NULL等价于node
        printf("%d ",node->element);
        node=node->next;
    }
}

int main() {
    struct ListNode head;
    initList(&head);
    for (int i = 1; i <= 10; ++i) {
        insertList(&head, i * 100, i);//尾插入
    }
    insertList(&head,0,5); //中间插入
    deleteList(&head, 3);   //这里我们尝试删除一下第三个元素
    printList(&head);
    printf("\n");
    printf("%d", sizeList(&head));
    printf("\n");
    printf("%d ", getList(&head,2));
    printf("\n");
    printf("%d ", findList(&head,500));
}