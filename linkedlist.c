#include"linkedlist.h"
#include<stdio.h>
#include<stdlib.h>

int count = 0;

void insert_at_begin(Node_t *start, int data) {
  struct Node_t *new_node;

  new_node = (struct Node_t*)malloc(sizeof(struct Node_t));
  new_node->data = data;
  count++;

  // if its the first node
  if (start == NULL) {
    start = new_node;
    start->next = NULL;
    return;
  }

  new_node->next = start;
  start = new_node;
}

void insert_at_end(Node_t *start, int data) {
  struct Node_t *new_node, *temp;

  new_node = (struct Node_t*)malloc(sizeof(struct Node_t));
  new_node->data = data;
  count++;

  if (start == NULL) {
    start = new_node;
    start->next = NULL;
    return;
  }

  temp = start;

  while (temp->next != NULL)
    temp = temp->next;

  temp->next = new_node;
  new_node->next = NULL;
}

void display(Node_t *start) {
  struct Node_t *new_node;

  new_node = start;

  if (new_node == NULL) {
    printf("Linked list is empty.\n");
    return;
  }

  printf("There are %d elements in linked list.\n", count);

  while (new_node->next != NULL) {
    printf("%d\n", new_node->data);
    new_node = new_node->next;
  }
  printf("%d\n", new_node->data); // Print last Node_t
}

void delete_from_begin(Node_t *start) {
  struct Node_t *new_node;
  int data;

  if (start == NULL) {
    printf("Linked list is empty.\n");
    return;
  }

  data = start->data;

  new_node = start->next;
  free(start);
  start = new_node;
  count--;

  printf("%d deleted from the beginning successfully.\n", data);
}

void delete_from_end(Node_t *start) {

  struct Node_t *new_node, *last;
  int data;

  if (start == NULL) {
    printf("Linked list is empty.\n");
    return;
  }

  count--;

  if (start->next == NULL) {
    data = start->data;

    free(start);
    start = NULL;
    printf("%d deleted from end successfully.\n", data);
    return;
  }

  new_node = start;

  while (new_node->next != NULL) {
    last = new_node;
    new_node = new_node->next;
  }

  data = new_node->data;
  last->next = NULL;
  free(new_node);

  printf("%d deleted from end successfully.\n", data);
}

