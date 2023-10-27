
//
// Created by shenjianZ on 2023/7/13.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int E;   // 元素类型

struct SeqList{
    E * array;      //底层数组
    int capacity;   // 容量
    int size;       //表长
};

typedef struct SeqList* List;  // 指针别名

bool initList(List list){
    list->array= malloc(sizeof(E)*10);
    if(list==NULL) return 0;
    list->capacity=10;
    list->size=0;
    return 1;
}

void printArrayList(List list){
    for (int i = 0; i < list->size; ++i)
        printf("%d ",list->array[i]);
    printf("\n");
}

/*
 * 索引合法范围 [1,size]
 */
bool insertList(List list,E element ,int index){
    if(index<1 || index>list->size+1) return 0;
    if(list->size==list->capacity){
        int newCapacity=list->capacity+(list->capacity>>1);
        E * newArray= realloc(list->array,sizeof(E) * newCapacity);
        if(newArray==NULL) return 0;
        list->array=newArray;
        list->capacity=newCapacity;
    }
    for (int i = list->size; i >=index ; --i)
        list->array[i]=list->array[i-1];
    list->array[index-1]=element;
    list->size++;
    return 1;
}

/*
 * 索引合法范围 [1,size]
 */
bool deleteList(List list, int index){
    if(index<1 || index>list->size) return 0;
    for (int i = index; i < list->size ; ++i) {
        list->array[i-1]=list->array[i];
    }
    list->size--;
    return 1;
}

void destroyList(List list){
    if(list==NULL) return;
    free(list->array);
    free(list);
}

E * getList(List list,int index){
    return &list->array[index-1];
}

bool setList(List list,int index,E element){
    if(index<1 || index>list->size) return false;
    list->array[index-1]=element;
    return true;
}

int findList(List list ,E element){
    for (int i = 0; i < list->size; ++i)
        if(list->array[i]==element) return i+1;
    return -1;
}

bool isEmptyList(List list){
    return list->size == 0;
}

bool isFullList(List list){
    return list->size == list->capacity;
}

int getCapacityList(List list){
    return list->capacity;
}

int sizeList(List list){
    return list->size;
}

bool setCapacityList(List list,int newCapacity){
    if(list->size > newCapacity && newCapacity > list->capacity)
        return false;
    int* newArray= realloc(list->array,sizeof(E)*newCapacity);
    if(newArray == NULL) return false;
    list->array=newArray;
    list->capacity=newCapacity;
    return true;
}

void clearList(List list){
    list->size=0;
}

int main(){
    struct SeqList list;
    if(initList(&list)){
        for (int i = 1; i < 10; ++i)
            insertList(&list, i, i);
        printArrayList(&list);
        printf("%d\n",*getList(&list,2));  //返回第二个元素
        printf("%d\n",findList(&list,5)); //返回元素 5 对应的索引;
        printf("%d",sizeList(&list)); //返回表长
        clearList(&list);
    }
}