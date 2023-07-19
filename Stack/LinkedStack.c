//
// Created by shenjianZ on 2023/7/19.
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

void initStack(Node head){
    head->next=NULL;
}
bool pushStack(Node head,E element){
    Node node = malloc(sizeof(struct ListNode));
    if(node==NULL) return 0;
    node->next=head->next;
    head->next=node;
    node->element=element;
    return 1;
}

E popStack(Node head){
    Node top=head->next;
    head->next=head->next->next;
    E element = top->element;
    free(top);
    return element;
}

E peekStack(Node head){
    return head->next->element;

}

void printStack(Node head){
    printf("| ");
    head=head->next;
    while(head!=NULL){
        printf("%d ",head->element);
        head=head->next;
    }
    printf("\n");
}

int main(){
    struct ListNode head;
    initStack(&head);
    for (int i = 0; i < 7; ++i) {
        pushStack(&head, i*100);
    }
    printf("%d\n", popStack(&head));
    printf("%d\n", peekStack(&head));
    printStack(&head);
}
