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

typedef struct ListNode* Node;

void initNode(Node node){
    node->next = node->prev = NULL;
}

int main() {
    struct ListNode head;
    initNode(&head);
}