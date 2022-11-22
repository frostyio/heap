#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>
#include "heap.h"

int integerCmp(void *a, void *b)
{
	return (int *)a > (int *)b;
}

#define N 50000
#define ITERATIONS 1000

#define TIME(ts) ((uint64_t)(ts.tv_sec * 1000000000L) + (uint64_t)ts.tv_nsec)

int main()
{

	for (int i = 0; i < 10000000; i++)
	{
	}

	struct timespec ts;

	u_int64_t sum = 0;

	for (int i = 0; i < ITERATIONS; i++)
	{
		int *nums[N];
		for (int n = 0; n < N; n++)
			nums[n] = (int *)rand();

		MinHeap *heap = newHeap(integerCmp);

		timespec_get(&ts, TIME_UTC);
		uint64_t start = TIME(ts);

		for (int n = 0; n < N; n++)
			insertHeap(heap, nums[n]);

		timespec_get(&ts, TIME_UTC);
		uint64_t end = TIME(ts);

		uint64_t diff = end - start;
		sum += diff;

		destroyHeap(heap);
	}

	printf("average of %" PRIu64 " ns per insert\n", sum / ITERATIONS / N);
	return 0;
}