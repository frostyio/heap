#ifndef MIN_HEAP
#define MIN_HEAP

#include <stdlib.h>

#define CAPACITY 50000

#define L(i) (2 * i + 1)
#define R(i) (2 * i + 2)
#define P(i) ((i - 1) / 2)

#define compare(heap, a, b) (heap->comparator(heap->elements[a], heap->elements[b]))

typedef int (*Comparator)(void *, void *);

typedef struct
{
	void **elements;
	unsigned int size;
	unsigned int capacity;
	Comparator comparator;
} MinHeap;

void swapHeap(MinHeap *heap, int a, int b);

MinHeap *newHeap(Comparator cmp);
void destroyHeap(MinHeap *heap);

void insertHeap(MinHeap *heap, void *element);
void *removeHeap(MinHeap *heap, int index);
void *removeFirstHeap(MinHeap *heap);
void heapify(MinHeap *heap, int index);

void *getFirst(MinHeap *heap);

#endif