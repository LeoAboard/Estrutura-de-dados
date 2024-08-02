#include <stdio.h>
#include <stdlib.h>

typedef enum {RED, BLACK} Color;

typedef struct Node{
    int data;
    Color color;
    struct node* left;
    struct node* right;
    struct node* parent;
}Node;

typedef struct RBtree{
    Node* root;
    Node* TNULL;
}RBtree;

void TreeStart(RBtree* tree){
    tree->TNULL = (Node*)malloc(sizeof(Node));
    tree->TNULL->color = BLACK;
    tree->TNULL->left = NULL;
    tree->TNULL->right = NULL;
    tree->root = tree->TNULL;
}

Node* criarNo(int data, Color color, Node* TNULL){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->color = color;
    node->left = TNULL;
    node->right = TNULL;
    node->parent = NULL;

    return node;
}



