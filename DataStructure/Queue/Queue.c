// Circular Queue
#define MAX_N 100000

typedef struct {
	int data[MAX_N];
	int front;
	int rear;
} Queue;

void init(Queue* q) {
	q->front = 0;
	q->rear = 0;
}

int empty(Queue* q) {
	return q->front == q->rear;
}

int size(Queue* q) {
	return(q->rear - q->front + MAX_N) % MAX_N;
}

int full(Queue* q) {
	return((q->rear + 1) % MAX_N) == q->front;
}

void push(Queue* q, int val) {
	if (full(q)) return;
	q->data[q->rear] = val;
	q->rear = (q->rear + 1) % MAX_N;
}

int pop(Queue* q) {
	if (empty(q)) return -1;
	int ret = q->data[q->front];
	q->front = (q->front + 1) % MAX_N;
	return ret;
}

int front(Queue* q) {
	if (empty(q)) return -1;
	return q->data[q->front];
}
