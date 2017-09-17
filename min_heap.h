#ifndef MIN_HEAP_H
#define MIN_HEAP_H

typedef struct node {
   int data ;
} node ;

typedef struct minHeap {
   int size ;
   node *elem ;
} minHeap ;

minHeap initMinHeap(int size);
void buildMinHeap(minHeap *hp, int *arr, int size);
void insertNode(minHeap *hp, int data);
void deleteNode(minHeap *hp);
void deleteMinHeap(minHeap *hp);
void preorderTraversal(minHeap *hp, int i);

#endif