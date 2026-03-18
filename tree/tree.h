#ifndef TREE_H
#define TREE_H

struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *createNode(int data);

void inOrder(struct tnode *root);
void preOrder(struct tnode *root);
void postOrder(struct tnode *root);

struct tnode *search(struct tnode *root, int key);
void insert(struct tnode *root, int key);
struct tnode *deleteNode(struct tnode *root, int val);

#endif