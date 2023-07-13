//
// Created by 15202 on 2023/7/13.
//
#include <stdio.h>
#include <stdlib.h>
typedef int E;   // 元素类型

struct List{
    E * array;  //底层数组
    int capacity;   // 容量
    int size;
};

typedef struct List * ArrayList;  // 指针别名

_Bool initList(ArrayList arrayList){
    arrayList->array= malloc(sizeof(E)*10);
    if(arrayList==NULL) return 0;
    arrayList->capacity=10;
    arrayList->size=0;
    return 1;
}

void printArrayList(ArrayList list){
    for (int i = 0; i < list->size; ++i)
        printf("%d ",list->array[i]);
    printf("\n");
}

_Bool insertList(ArrayList list,E element ,int index){
    if(index<1 || index>list->size+1) return 0;
    if(list->size==list->capacity){
        int newCapacity=list->capacity+(list->capacity>>1);
        E * newarray= realloc(list->array,sizeof(E) * newCapacity);
        if(newarray==NULL) return 0;
        list->array=newarray;
        list->capacity=newCapacity;
    }
    for (int i = list->size; i >=index ; --i)
        list->array[i]=list->array[i-1];
    list->array[index-1]=element;
    list->size++;
    return 1;
}

_Bool deleteList(ArrayList list, int index){
    if(index<1 || index>list->size) return 0;
    for (int i = index; i < list->size ; ++i) {
        list->array[i-1]=list->array[i];
    }
    list->size--;
    return 1;
}

int sizeList(ArrayList list){
    return list->size;
}

E * getList(ArrayList list,int index){
    return &list->array[index-1];
}

int findList(ArrayList list ,E element){
    for (int i = 0; i < list->size; ++i)
        if(list->array[i]==element) return i+1;
    return -1;
}

int main(){
    struct List list;
    if(initList(&list)){
        for (int i = 0; i < 30; ++i)
            insertList(&list, i, i);
        printArrayList(&list);
        printf("%d",getList(&list,2));
        printf("\n");
        printf("%d",findList(&list,5));
        printf("\n");
        printf("%d",sizeList(&list));


    }
    else{
        printf("%s","初始化失败");
    }
}

























