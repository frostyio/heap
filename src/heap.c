#include <stdio.h>
#include "heap.h"

void swapHeap(MinHeap *heap, int a, int b)
{
	void *temp = heap->elements[b];
	heap->elements[b] = heap->elements[a];
	heap->elements[a] = temp;
}

MinHeap *newHeap(Comparator cmp)
{
	MinHeap *heap = malloc(sizeof *heap);
	heap->size = 0;
	heap->capacity = CAPACITY;
	heap->comparator = cmp;

	void **elements = malloc(sizeof *elements * CAPACITY);
	heap->elements = elements;

	return heap;
}

void destroyHeap(MinHeap *heap)
{
	free(heap->elements);
	free(heap);
}

void insertHeap(MinHeap *heap, void *element)
{
	// dynamically expand
	if (heap->size + 1 >= heap->capacity)
	{
		heap->capacity *= 2;

		void **newElements = malloc(sizeof *newElements * heap->capacity);
		for (int i = 0; i < heap->size; i++)
			newElements[i] = heap->elements[i];

		free(heap->elements);
		heap->elements = newElements;
	}

	// structure
	int index = heap->size;
	heap->size++;
	heap->elements[index] = element;

	// fix order
	while (index > 0 && compare(heap, P(index), index))
	{
		swapHeap(heap, index, P(index));
		index = P(index);
	}
}

void heapify(MinHeap *heap, int index)
{
	int left = L(index);
	int right = R(index);
	int toSwap = index;

	if (compare(heap, left, index) || compare(heap, right, index))
		if (!compare(heap, left, right))
			toSwap = left;
		else
			toSwap = right;

	if (toSwap != index)
	{
		swapHeap(heap, index, toSwap);
		heapify(heap, toSwap);
	}
}

void *removeHeap(MinHeap *heap, int index)
{
	void *removed = heap->elements[index];

	// replace index with last
	heap->elements[index] = heap->elements[heap->size];
	heap->size--;

	// check integrity
	heapify(heap, index);

	return removed;
}

void *removeFirstHeap(MinHeap *heap)
{
	return removeHeap(heap, 0);
}

void *getFirst(MinHeap *heap)
{
	return heap->elements[0];
}