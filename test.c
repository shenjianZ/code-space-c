#include <stdio.h>

//
// Created by 15202 on 2023/8/21.
//
int main(){
    int a = 20;
    int * p = &a;
    int ** pp = &p;

    printf("p = %p, a = %d", *pp, **pp);  //ʹ��һ��*��ʾ����ָ��ָ���ָ�����������ʹ��һ��*�����������ָ�������ָ����ͨ����
}