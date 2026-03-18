#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct tnode *createNode(int data)
{
    struct tnode *n = (struct tnode *)malloc(sizeof(struct tnode));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrder(struct tnode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct tnode *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct tnode *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

struct tnode *search(struct tnode *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

void insert(struct tnode *root, int key)
{
    struct tnode *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("can not insert %d , already in BST!", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct tnode *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

struct tnode *inOrderPredecessor(struct tnode *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct tnode *deleteNode(struct tnode *root, int val)
{
    struct tnode *iprev;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        iprev = inOrderPredecessor(root);
        root->data = iprev->data;
        root->left = deleteNode(root->left, iprev->data);
    }
    return root;
}
