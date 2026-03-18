#include <stdio.h>
#include <stdlib.h>

#include "stack/stack.h"
#include "queue/queue.h"
#include "linkedlist/linkedlist.h"
#include "tree/tree.h"

int main()
{
    // ================= STACK =================
    printf("---- STACK ----\n");

    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    push(sp, 5);
    push(sp, 15);
    push(sp, 25);

    printf("Popped: %d\n", pop(sp));
    printf("Popped: %d\n\n", pop(sp));

    // ================= QUEUE =================
    printf("---- QUEUE ----\n");

    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 5;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n\n", dequeue(q));

    // ================= LINKED LIST =================
    printf("---- LINKED LIST ----\n");

    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = NULL;

    printf("Initial List:\n");
    linkedlist_traversal(head);

    head = insertion_at_beginning(head, 5);
    head = insert_at_end(head, 30);

    printf("\nAfter Insertions:\n");
    linkedlist_traversal(head);

    head = delete_givenvalue(head, 10);

    printf("\nAfter Deleting 10:\n");
    linkedlist_traversal(head);

    // ================= TREE (BST) =================
    printf("\n---- TREE (BST) ----\n");

    struct tnode *root = createNode(7);
    struct tnode *p1 = createNode(3);
    struct tnode *p2 = createNode(11);
    struct tnode *p3 = createNode(1);
    struct tnode *p4 = createNode(4);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Inorder: ");
    inOrder(root);

    printf("\nPreorder: ");
    preOrder(root);

    printf("\nPostorder: ");
    postOrder(root);

    struct tnode *found = search(root, 4);
    printf("\nSearching 4: %s\n", (found != NULL) ? "Found" : "Not Found");

    insert(root, 10);

    printf("After insertion (inorder): ");
    inOrder(root);

    root = deleteNode(root, 3);

    printf("\nAfter deletion (inorder): ");
    inOrder(root);

    printf("\n");

    return 0;
}