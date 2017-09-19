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
void deleteMinHeap(minHeap *hp);
int isEmpty(minHeap *hp);
void buildMinHeap(minHeap *hp, int *arr, char *arr2, char*arr3, int size);
void insertNode(minHeap *hp, int data, char x_position, char y_position);
node deleteMin(minHeap *hp);
void deleteMinHeap(minHeap *hp);
void decreasePriority(int data, )
void preorderTraversal(minHeap *hp, int i);

#endif