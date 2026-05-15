#include <stdio.h>

#define MAX_SIZE 100000

typedef struct {
	int node;
	int cost;
} PQ;

PQ heap[MAX_SIZE + 1];
int heapSize;

int compare(PQ a, PQ b) {
	return a.cost < b.cost;
}

void push(PQ value) {
	int idx = ++heapSize;
	
	while (idx > 1) {
		int parent = idx / 2;

		if (compare(heap[parent], value)) break;

		heap[idx] = heap[parent];
		idx = parent;
	}

	heap[idx] = value;
}

PQ pop() {
	PQ ret = heap[1];
	PQ last = heap[heapSize--];

	int parent = 1;
	int child = 2;

	while (child <= heapSize) {
		if (child + 1 <= heapSize && compare(heap[child + 1], heap[child])) {
			child++;
		}

		if (compare(last, heap[child])) break;

		heap[parent] = heap[child];

		parent = child;
		child = parent * 2;
	}

	heap[parent] = last;
	return ret;
}

int empty() {
	return heapSize == 0;
}
