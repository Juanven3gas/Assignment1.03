#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2

typedef struct node {
   int data ;
   char x_position;
   char y_position;
} node ;

typedef struct minHeap {
   int size ;
   node *elem ;
} minHeap ;

minHeap initMinHeap(void);
void buildMinHeap(minHeap *hp, int *arr, int size);
void insertNode(minHeap *hp, int data, char x_position, char y_position);
void deleteNode(minHeap *hp);
void deleteMinHeap(minHeap *hp);
void preorderTraversal(minHeap *hp, int i);

#endif