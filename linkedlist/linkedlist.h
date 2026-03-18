#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node
{
    int data;
    struct node *next;
};

void linkedlist_traversal(struct node *ptr);

struct node *insertion_at_beginning(struct node *head, int data);
struct node *insert_at_index(struct node *head, int data, int index);
struct node *insert_at_end(struct node *head, int data);
struct node *insert_after_node(struct node *head, struct node *prevnode, int data);

struct node *delete_first(struct node *head);
struct node *delete_at_index(struct node *head, int index);
struct node *delete_end(struct node *head);
struct node *delete_givenvalue(struct node *head, int value);

#endif