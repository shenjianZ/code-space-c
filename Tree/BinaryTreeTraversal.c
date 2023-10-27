//
// Created by shenjianZ on 2023/10/18.
//
#include <stdlib.h>
#include <stdio.h>
typedef char E;
typedef struct TreeNode * Node;
//------------- 栈 -------------------
typedef Node T;   //这里栈内元素类型定义为上面的Node，也就是二叉树结点指针

struct StackNode {
    T element;
    struct StackNode * next;
};

typedef struct StackNode * SNode;  //这里就命名为SNode，不然跟上面冲突了就不好了

void initStack(SNode head){
    head->next = NULL;
}

_Bool pushStack(SNode head, T element){
    SNode node = malloc(sizeof(struct StackNode));
    if(node == NULL) return 0;
    node->next = head->next;
    node->element = element;
    head->next = node;
    return 1;
}

_Bool isEmpty(SNode head){
    return head->next == NULL;
}
T peekStack(SNode head){   //这里新增一个peek操作，用于获取栈顶元素的值，但是不出栈，仅仅是值获取
    return head->next->element;
}

T popStack(SNode head){
    SNode top = head->next;
    head->next = head->next->next;
    T e = top->element;
    free(top);
    return e;
}



struct TreeNode {
    E element;    //存放元素
    struct TreeNode * left;   //指向左子树的指针
    struct TreeNode * right;   //指向右子树的指针
    int flag;   //需要经历左右子树都被遍历才行，这里用flag存一下状态，0表示左子树遍历完成，1表示右子树遍历完成（辅助后序遍历进行）
};

typedef struct TreeNode * Node;

/**
 * 前序遍历二叉树，并打印节点的元素值。
 * 使用递归
 * @param root 二叉树的根节点指针
 */
/*void preOrder(Node root) {
    // 如果当前节点为空，直接返回
    if (root == NULL) return;
    // 打印当前节点的元素值
    printf("%c", root->element);
    // 递归遍历左子树，先序遍历左子树
    preOrder(root->left);
    // 递归遍历右子树，先序遍历右子树
    preOrder(root->right);
}*/
/**
 * 前序遍历二叉树，并打印节点的元素值。
 * 未使用递归
 * @param root 二叉树的根节点指针
 */
void preOrder(Node root) {
    // 创建一个栈节点作为栈的头结点
    struct StackNode head;
    // 初始化栈
    initStack(&head);
    // 当根节点不为空或栈不为空时，进行遍历
    while (root != NULL || !isEmpty(&head)) {
        // 当根节点不为空时，沿着左子树一直遍历到最左边的节点
        while (root != NULL) {
            // 将当前节点压入栈中
            pushStack(&head, root);
            // 打印当前节点的元素值
            printf("%c", root->element);
            // 移动到左子树继续遍历
            root = root->left;
        }
        // 当根节点为空时，从栈中弹出节点，然后遍历右子树
        Node node = popStack(&head);
        root = node->right;
    }
}

/**
 * 中序遍历二叉树，并打印节点的元素值。
 * 使用递归
 * @param root 二叉树的根节点指针
 */
/*void inOrder(Node root) {
    // 如果当前节点为空，直接返回
    if (root == NULL) return;
    // 递归遍历左子树，中序遍历左子树
    inOrder(root->left);
    // 打印当前节点的元素值
    printf("%c", root->element);
    // 递归遍历右子树，中序遍历右子树
    inOrder(root->right);
}*/
/**
 * 中序遍历二叉树，并打印节点的元素值。
 * 未使用递归
 * @param root 二叉树的根节点指针
 */
void inOrder(Node root){
    struct StackNode head;
    initStack(&head);
    while(root || !isEmpty(&head)){
        while(root){
            pushStack(&head,root);
            root=root->left;
        }
        root= popStack(&head);
        printf("%c",root->element);
        root=root->right;
    }
}

/**
 * 后序遍历二叉树，并打印节点的元素值。
 * 使用递归
 * @param root 二叉树的根节点指针
 */
/*void postOrder(Node root) {
    // 如果当前节点为空，直接返回
    if (root == NULL) return;
    // 递归遍历左子树，后序遍历左子树
    postOrder(root->left);
    // 递归遍历右子树，后序遍历右子树
    postOrder(root->right);
    // 打印当前节点的元素值
    printf("%c", root->element);
}*/
/**
 * 后序遍历二叉树，并打印节点的元素值。
 * 未使用递归
 * @param root 二叉树的根节点指针
 */
void postOrder(Node root) {
    struct StackNode head;
    initStack(&head);
    while(root || !isEmpty(&head)){
        while(root){
            pushStack(&head,root);
            root->flag=0;
            root=root->left;
        }
        root= peekStack(&head);
        if(root->flag==0){
            root->flag=1;
            root=root->right;
        }else{
            printf("%c",root->element);
            popStack(&head);
            root=NULL;
        }
    }
}
int main(){
    Node a = malloc(sizeof(struct TreeNode));
    Node b = malloc(sizeof(struct TreeNode));
    Node c = malloc(sizeof(struct TreeNode));
    Node d = malloc(sizeof(struct TreeNode));
    Node e = malloc(sizeof(struct TreeNode));
    Node f = malloc(sizeof(struct TreeNode));
    a->element = 'A';
    b->element = 'B';
    c->element = 'C';
    d->element = 'D';
    e->element = 'E';
    f->element = 'F';

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    c->left = NULL;
    d->left = d->right = NULL;
    e->left = e->right = NULL;
    f->left = f->right = NULL;
    preOrder(a);
    printf("\n");
    inOrder(a);
    printf("\n");
    postOrder(a);
}