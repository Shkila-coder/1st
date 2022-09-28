﻿#include <iostream>

struct list {
	int field;
	struct list* ptr;
};
struct queue {
	struct list* frnt, * rear;
};

void init(struct queue* q) {
	q->frnt = 0;
	q->rear = 0;
}

int isempty(struct queue* q) {
	if (q->frnt == 0)
		return 1;
	else
		return 0;
}

void insert(struct queue* q, int x) {
	if ((q->rear == 0) && (q->frnt == 0)) {
		q->rear = init(x);
		q->frnt = q->rear;
	}
	else
		q->rear = addelem(q->rear, x);
}

void print(struct queue* q) {
	struct list* h;
	if (isempty(q) == 1) {
		printf("Очередь пуста!\n");
		return;
	}
	for (h = q->frnt; h != NULL; h = h->ptr)
		printf("%d ", h->field);
	return;
}

int remove(struct queue* q) {
	struct list* temp;
	int x;
	if (isempty(q) == 1) {
		printf("Очередь пуста!\n");
		return 0;
	}
	x = q->frnt->field;
	temp = q->frnt;
	q->frnt = q->frnt->ptr;
	free(temp);
	return x;
}

int test(struct queue* q) {
	int x;
	x = q->frnt->field;
	return x;
}

int main() {
	struct queue* q;
	int a;
	//system("chcp 1251");
	system("cls");
	q = (queue*)malloc(sizeof(queue*));
	init(q);
	print(q);
	for (int i = 0; i < 8; i++) {
		printf("Введите элемент очереди: ");
		scanf("%d", &a);
		insert(q, a);
	}
	printf("\n");
	print(q);
	while (q->frnt != NULL) {
		a = remove(q);
		printf("\nУдален элемент %d\n", a);
		print(q);
	}
	getchar(); getchar();
	return 0;
}