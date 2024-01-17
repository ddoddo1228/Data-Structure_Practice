#include<stdio.h>

#define max_size 100

typedef struct Stacktype {
	int stack[max_size];
	int top;
}Stacktype;

void Stack_init(Stacktype* s) {
	s->top = -1;
}

void Stack_push(Stacktype* s, int item) {
	s->stack[++(s->top)] = item;
	
	return;
}

bool is_empty(Stacktype* s) {
	return s->top == -1;
}

int Stack_pop(Stacktype* s) {
	int t = s->stack[s->top];
	s->stack[s->top] = 0;
	s->top--;


	return t;
}

int main(void) {

	int n, temp;
	Stacktype s;
	Stack_init(&s);

	printf("���� �迭�� ũ�� : ");
	scanf("%d", &n);
	printf("������ �Է��Ͻÿ� : ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		Stack_push(&s, temp);
	}
	printf("������ ���� �迭 : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", Stack_pop(&s));
	}
	return 0;
}
