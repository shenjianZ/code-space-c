//
// Created by shenjianZ on 2023/7/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

//带头结点的单链表，即头结点不存储数据

struct ListNode{
    E element;
    struct ListNode * next;
};

struct SinglyList{
    struct ListNode* head;
    struct ListNode* tail;
    int size;
};

typedef struct SinglyList * List;

typedef struct ListNode * Node;

void initList(List list){
    list->head= malloc(sizeof (struct ListNode));
    list->tail= malloc(sizeof (struct ListNode));
    list->head->next=list->tail->next=NULL;
    list->size=0;
}

/*
 * 索引的合法插入范围 [1,size+1]，即包含了首插入、尾插入
 */
bool insertList(List list, E element, int index){
    Node head=list->head;
    if(list==NULL || index<1 || index>list->size+1) return 0;
    Node newNode= malloc(sizeof (struct ListNode));
    newNode->element=element;
    //首先空表时插入，表长为0
    if(list->head->next==NULL){
        list->tail->element=element;
        head->next=list->tail;
        list->tail->next=NULL;
        list->size++;
        return 1;
    }
    //其次是首插入，但表长不为0
    if(index==1){
        newNode->next=head->next;
        head->next=newNode;
        list->size++;
        return 1;
    }
    //再其次是尾插入，但表长不为0
    if(index==list->size+1){
        list->tail->next=newNode;
        newNode->next=NULL;
        list->tail=newNode;
        list->size++;
        return 1;
    }
   //再再其次是中间插入 索引范围：[2,size]
    Node front=head;
    while (index>1){
        front=front->next;
        index--;
    }
    head=front->next;
    //Node temp=front->next;
    //front->next=newNode;
    //newNode->next=temp;
    front->next=newNode;
    newNode->next=head;
    list->size++;
    //也可以，与前30-32代码作用相同
    return 1;
}

/*
 * 索引的合法删除范围 [1,size]
 */
bool deleteList(List list, int index){
    Node head=list->head;
    if(head==NULL || index<1 || index>list->size) return 0;
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
    list->size--;
    return 1;
}

/*
 * 返回元素 索引的合法范围 [1,size]
 */
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

/*
 *  索引合法范围 [1,size]
 *
 */
void setList(List list,E element, int index) {
    Node head=list->head;
    if (head == NULL || index < 1)
        return;
    Node front = head;
    while (index > 1) {
        front = front->next;
        index--;
    }
    head = front->next;
    if (head != NULL)
        head->element=element;
}
/*
 * 返回元素的索引 索引合法范围 [1,size]
 */
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

int sizeList(List list){
    Node head=list->head;
    //因为头结点没有存储数据
    int resSize=-1;
    Node node = head;
    while(node!=NULL){
        //while循环条件中的node!=NULL等价于node
        node=node->next;
        resSize++;
    }
    return resSize;
//    return list->size; 注意，此处也可直接返回维护的表长，无需遍历节点
}

void printList(List list){
    Node head=list->head;
    Node node = head->next;
    while(node!=NULL){
        //while循环条件中的node!=NULL等价于node
        printf("%d ",node->element);
        node=node->next;
    }
}

int main() {
    struct SinglyList singlyList;
    initList(&singlyList);
    for (int i = 1; i <= 10; ++i) {
        insertList(&singlyList, i * 100, i);//尾插入
    }
    setList(&singlyList,0,1); //修改第一个元素
    insertList(&singlyList,0,5); //中间插入
    deleteList(&singlyList, 3);   //这里我们尝试删除一下第三个元素
    printList(&singlyList);
    printf("\n");
    printf("%d\n", sizeList(&singlyList));
    printf("%d\n ", getList(&singlyList,2));
    printf("%d ", findList(&singlyList,500));
}