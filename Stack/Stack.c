#define MAX_N 100000

typedef struct{
	int idx;
	int data[MAX_N];
}Stack;

void init(Stack* s) {
	s->idx = 0;
}

int empty(Stack* s) {
	return s->idx == 0;
}

int size(Stack* s) {
	return s->idx;	
}

void push(Stack* s, int val) {
	if (s->idx == MAX_N) return;
	s->data[s->idx++] = val;
}

void pop(Stack* s) {
	if (empty(s)) return;
	s->idx--;
}

int top(Stack* s) {
	if (empty(s)) return -1;
	return s->data[s->idx- 1];
}
