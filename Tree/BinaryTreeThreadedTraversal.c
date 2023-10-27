//
// Created by jianyu on 2023/10/19.
//
#include <stdlib.h>
#include <stdio.h>

typedef char E;

struct TreeNode {
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    struct TreeNode * parent;
    int leftTag;
    int rightTag;
};

typedef struct TreeNode * Node;

/**
 * 创建一个新的节点
 * @param element 节点元素值
 * @return 新的节点
 */
Node createNode(E element) {
    Node node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->rightTag = node->leftTag = 0;
    node->element = element;
    return node;
}

Node pre = NULL;

/**
 * 对二叉树进行前序线索化
 * @param root 二叉树根节点
 */
void preOrderThreaded(Node root) {
    if (root == NULL) return;
    if (root->left == NULL) {
        root->left = pre;
        root->leftTag = 1;
    }
    if (pre && pre->right == NULL) {
        pre->right = root;
        pre->rightTag = 1;
    }
    pre = root;
    if (root->leftTag == 0)
        preOrderThreaded(root->left);
    if (root->rightTag == 0)
        preOrderThreaded(root->right);
}

/**
 * 前序遍历二叉树（非递归方式）
 * @param root 二叉树根节点
 */
void preOrder(Node root) {
    while (root) {
        printf("%c", root->element);
        if (root->leftTag == 0)
            root = root->left;
        else
            root = root->right;
    }
}

/**
 * 对二叉树进行中序线索化
 * @param root 二叉树根节点
 */
void inOrderThreaded(Node root) {
    if (root == NULL) return;
    if (root->leftTag == 0)
        inOrderThreaded(root->left);
    if (root->left == NULL) {
        root->left = pre;
        root->leftTag = 1;
    }
    if (pre && pre->right == NULL) {
        pre->right = root;
        pre->rightTag = 1;
    }
    pre = root;
    if (root->rightTag == 0)
        inOrderThreaded(root->right);
}

/**
 * 中序遍历二叉树（非递归方式）
 * @param root 二叉树根节点
 */
void inOrder(Node root) {
    while (root) {
        while (root && root->leftTag == 0)
            root = root->left;
        printf("%c", root->element);
        while (root && root->rightTag == 1) {
            root = root->right;
            printf("%c", root->element);
        }
        root = root->right;
    }
}

/**
 * 对二叉树进行后序线索化
 * @param root 二叉树根节点
 */
void postOrderThreaded(Node root) {
    if (root == NULL) return;
    if (root->leftTag == 0) {
        postOrderThreaded(root->left);
        if (root->left)
            root->left->parent = root;
    }
    if (root->rightTag == 0) {
        postOrderThreaded(root->right);
        if (root->right)
            root->right->parent = root;
    }
    if (root->left == NULL) {
        root->left = pre;
        root->leftTag = 1;
    }
    if (pre && pre->right == NULL) {
        pre->right = root;
        pre->rightTag = 1;
    }
    pre = root;
}

/**
 * 后序遍历二叉树（非递归方式）
 * @param root 二叉树根节点
 */
void postOrder(Node root) {
    Node last = NULL, node = root;
    while (node) {
        while (node->left != last && node->leftTag == 0)
            node = node->left;
        while (node && node->rightTag == 1) {
            printf("%c", node->element);
            last = node;
            node = node->right;
        }
        if (node == root && node->right == last) {
            printf("%c", node->element);
            return;
        }
        while (node && node->right == last) {
            printf("%c", node->element);
            last = node;
            node = node->parent;
        }
        if (node && node->rightTag == 0)
            node = node->right;
    }
}

int main() {
    Node a = createNode('A');
    Node b = createNode('B');
    Node c = createNode('C');
    Node d = createNode('D');
    Node e = createNode('E');

    a->left = b;
    b->left = d;
    a->right = c;
    b->right = e;

//    preOrderThreaded(a);
//    preOrder(a);

//    inOrderThreaded(a);
//    inOrder(a);

//    postOrderThreaded(a);
//    postOrder(a);
}