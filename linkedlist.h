#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED


     typedef struct Node_t {
        int data;
        struct Node_t *next;
        }Node_t;

    void insert_at_begin(Node_t *start, int data);
    void insert_at_end(Node_t *start, int data);
    void traverse(Node_t *start);
    void delete_from_begin(Node_t *start);
    void delete_from_end(Node_t *start);





#endif // LINKEDLIST_H_INCLUDED
