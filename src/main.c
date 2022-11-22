#include <stdio.h>
#include "heap.h"

int integerCmp(void *a, void *b)
{
	return (int *)a > (int *)b;
}

int main()
{
	MinHeap *heap = newHeap(integerCmp);
	insertHeap(heap, (int *)5);
	insertHeap(heap, (int *)6);
	insertHeap(heap, (int *)2);
	insertHeap(heap, (int *)3);
	insertHeap(heap, (int *)7);

	printf("minimum: %d\n", removeFirstHeap(heap));
	printf("next minimum: %d\n", getFirst(heap));

	destroyHeap(heap);
	return 0;
}