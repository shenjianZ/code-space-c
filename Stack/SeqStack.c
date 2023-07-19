//
// Created by shenjianZ on 2023/7/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int E;

struct SeqStack{
    E * array;
    int capacity;
    int top;
};

typedef struct SeqStack * Stack;

bool initStack(Stack stack){
    stack->capacity=10;
    stack->array= malloc(sizeof (E)*stack->capacity);
    if(stack == NULL) return 0;
    stack->top=-1;
    return 1;
}

bool pushStack(Stack stack,E element){
    if(stack == NULL) return 0;
    if(stack->top==stack->capacity-1){
        int newCapacity = stack->capacity + (stack->capacity>>1);
        E * newArray= realloc(stack->array,sizeof(E) * newCapacity);
        if(newArray == NULL) return 0;
        stack->capacity=newCapacity;
        stack->array=newArray;
    }
    stack->top++;
    stack->array[stack->top]=element;
    return 1;
}

E peekStack(Stack stack){
    if(stack->top<0) return -1;
    return stack->array[stack->top];
}

E popStack(Stack stack){
    if(stack->top<0) return -1;
    return stack->array[stack->top--];

}

void printStack(Stack stack){
    printf("| ");
    for (int i = 0; i < stack->top + 1; ++i) {
        if(i==stack->top){
            printf("%d ", stack->array[i]);
            return;
        }
        printf("%d, ", stack->array[i]);
    }
    printf("\n");
}

int main(){
    struct SeqStack stack;
    initStack(&stack);
    for (int i = 0; i <= 7; ++i)
        pushStack(&stack, i*100);
    printStack(&stack);
}