#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct _Node {
	int importance;
	int idx;
	struct _Node *prev;
	struct _Node *next;
} Node;

typedef struct _Deque {
	size_t sz_;
	Node *head;
	Node *tail;
} Deque;

Deque *printer;

int N, M;
int importances[MAX];

int init();
void solve();
void destroy();

int cmp(const void *, const void *);

Node *init_node(int, int);

int push_front(int, int);
int push_back(int, int);
void pop_front();
void pop_back();
int size();
int empty();
Node *front();
Node *back();

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		if (init()) {
			solve();
			destroy();
		}
	}
	return 0;
} // end of main

int init() {
	scanf("%d %d", &N, &M);
	printer = (Deque *) malloc(sizeof(Deque));
	if (!printer)
		return 0;
	printer->sz_ = 0;
	printer->head = printer->tail = 0;
	for (int i=0; i<N; i++) {
		int importance;
		scanf("%d", &importance);
		importances[i] = importance;
		push_back(importance, i);
	}
	qsort(importances, N, sizeof(int), cmp);
	return 1;
}

void solve() {
	while (!empty()) {
		if (importances[size()-1] == front()->importance && front()->idx == M) {
			printf("%d\n", N-size()+1);
			return;
		}
		if (importances[size()-1] != front()->importance)
			push_back(front()->importance, front()->idx);
		pop_front();
	}
	return;
}

void destroy() {
	if (!printer)
		return;
	Node *tmp = printer->head;
	Node *to_del;
	while (tmp) {
		to_del = tmp;
		tmp = tmp->next;
		free(to_del);
	}
	free(printer);
	return ;
}

int cmp(const void *a, const void *b) {
	return (*(int *)a > *(int *)b);
}

Node *init_node(int importance, int idx) {
	Node *ret = (Node *) malloc(sizeof(Node));
	if (!ret)
		return 0;
	ret->importance = importance;
	ret->idx = idx;
	ret->prev = ret->next = 0;
	return ret;
}

int push_front(int importance, int idx) {
	Node *document = init_node(importance, idx);
	if (!document)
		return 0;
	if (empty())
		printer->head = printer->tail = document;
	else {
		document->next = printer->head;
		printer->head->prev = document;
		printer->head = document;
	}
	printer->sz_++;
	return 1;
}

int push_back(int importance, int idx) {
	Node *document = init_node(importance, idx);
	if (!document)
		return 0;
	if (empty())
		printer->head = printer->tail = document;
	else {
		printer->tail->next = document;
		document->prev = printer->tail;
		printer->tail = document;
	}
	printer->sz_++;
	return 1;
}

void pop_front() {
	if (empty())
		return;
	Node *poped;
	if (printer->head == printer->tail) {
		poped = printer->head;
		printer->head = printer->tail = 0;
	} else {
		poped = printer->head;
		printer->head = printer->head->next;
		printer->head->prev = 0;
	}
	free(poped);
	printer->sz_--;
	return;
}

void pop_back() {
	if (empty())
		return;
	Node *poped;
	if (printer->head == printer->tail) {
		poped = printer->head;
		printer->head = printer->tail = 0;
	} else {
		poped = printer->tail;
		printer->tail = printer->tail->prev;
		printer->tail->next = 0;
	}
	free(poped);
	printer->sz_--;
	return;
}

int size() {
	return (printer->sz_);
}

int empty() {
	return (!printer->sz_);
}

Node *front() {
	if (empty())
		return NULL;
	return printer->head;
}

Node *back() {
	if (empty())
		return NULL;
	return printer->tail;
}