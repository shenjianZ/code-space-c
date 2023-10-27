#include <stdio.h>

//
// Created by 15202 on 2023/8/21.
//
int main(){
    int a = 20;
    int * p = &a;
    int ** pp = &p;

    printf("p = %p, a = %d", *pp, **pp);  //使用一次*表示二级指针指向的指针变量，继续使用一次*会继续解析成指针变量所指的普通变量
}