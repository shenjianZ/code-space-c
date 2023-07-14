
//
// Created by shenjianZ on 2023/7/13.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int E;   // 元素类型

struct List{
    E * array;  //底层数组
    int capacity;   // 容量
    int size;
};

typedef struct List * SeqList;  // 指针别名

bool initList(SeqList list){
    list->array= malloc(sizeof(E)*10);
    if(list==NULL) return 0;
    list->capacity=10;
    list->size=0;
    return 1;
}

void printArrayList(SeqList list){
    for (int i = 0; i < list->size; ++i)
        printf("%d ",list->array[i]);
    printf("\n");
}

bool insertList(SeqList list,E element ,int index){
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

bool deleteList(SeqList list, int index){
    if(index<1 || index>list->size) return 0;
    for (int i = index; i < list->size ; ++i) {
        list->array[i-1]=list->array[i];
    }
    list->size--;
    return 1;
}

void destroyList(SeqList list){
    if(list==NULL) return;
    free(list->array);
    free(list);
}

E * getList(SeqList list,int index){
    return &list->array[index-1];
}

bool setList(SeqList list,int index,E element){
    if(index<1 || index>list->size) return false;
    list->array[index-1]=element;
    list->size++;
    return true;
}

int findList(SeqList list ,E element){
    for (int i = 0; i < list->size; ++i)
        if(list->array[i]==element) return i+1;
    return -1;
}

bool isEmptyList(SeqList list){
    return list->size == 0;
}

bool isFullList(SeqList list){
    return list->size == list->capacity;
}

int getCapacityList(SeqList list){
    return list->capacity;
}

int sizeList(SeqList list){
    return list->size;
}

bool setCapacityList(SeqList list,int newCapacity){
    if(list->size > newCapacity) return false;
    int* newArray= realloc(list->array,sizeof(E)*newCapacity);
    if(newArray == NULL) return false;
    list->array=newArray;
    list->capacity=newCapacity;
    return true;
}

void clearList(SeqList list){
    list->size=0;
}

int main(){
    struct List list;
    if(initList(&list)){
        for (int i = 0; i < 30; ++i)
            insertList(&list, i, i);
        printArrayList(&list);
        printf("%d",*getList(&list,2));
        printf("\n");
        printf("%d",findList(&list,5));
        printf("\n");
        printf("%d",sizeList(&list));


    }
    else{
        printf("%s","初始化失败");
    }
}

























