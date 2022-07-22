#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
	int val;
	struct _Node *prev;
	struct _Node *next;
} Node;

typedef struct _Deque {
	size_t sz_;
	Node *head;
	Node *tail;
} Deque;

Deque *dq;
int N;

int init();
void solve();
void destroy();

Node *init_node(int);

int push_front(int);
int push_back(int);
int pop_front();
int pop_back();
int size();
int empty();
int front();
int back();

int main() {
	if (init()) {
		solve();
		destroy();
	}
	return 0;
} // end of main

int init() {
	scanf("%d", &N);
	dq = (Deque *) malloc(sizeof(Deque));
	if (!dq)
		return 0;
	dq->sz_ = 0;
	dq->head = dq->tail = 0;
	return 1;
}

void solve() {
	char command[11];
	int val;
	while (N--) {
		scanf("%s", command);
		if (!strcmp(command, "push_front")) {
			scanf("%d", &val);
			if (!push_front(val))
				return;
		}
		else if (!strcmp(command, "push_back")) {
			scanf("%d", &val);
			if (!push_back(val))
				return;
		}
		else if (!strcmp(command, "pop_front"))
			printf("%d\n", pop_front());
		else if (!strcmp(command, "pop_back"))
			printf("%d\n", pop_back());
		else if (!strcmp(command, "size"))
			printf("%d\n", size());
		else if (!strcmp(command, "empty"))
			printf("%d\n", empty());
		else if (!strcmp(command, "front"))
			printf("%d\n", front());
		else if (!strcmp(command, "back"))
			printf("%d\n", back());
		else {
			printf("Error: Invalid command.\n");
			return;
		}
	}
	return;
}

void destroy() {
	if (!dq)
		return;
	Node *tmp = dq->head;
	Node *to_del;
	while (tmp) {
		to_del = tmp;
		tmp = tmp->next;
		free(to_del);
	}
	free(dq);
	return ;
}

Node *init_node(int num) {
	Node *ret = (Node *) malloc(sizeof(Node));
	if (!ret)
		return 0;
	ret->val = num;
	ret->prev = ret->next = 0;
	return ret;
}

int push_front(int num) {
	Node *to_insert = init_node(num);
	if (!to_insert)
		return 0;
	if (empty())
		dq->head = dq->tail = to_insert;
	else {
		to_insert->next = dq->head;
		dq->head->prev = to_insert;
		dq->head = to_insert;
	}
	dq->sz_++;
	return 1;
}

int push_back(int num) {
	Node *to_insert = init_node(num);
	if (!to_insert)
		return 0;
	if (empty())
		dq->head = dq->tail = to_insert;
	else {
		dq->tail->next = to_insert;
		to_insert->prev = dq->tail;
		dq->tail = to_insert;
	}
	dq->sz_++;
	return 1;
}

int pop_front() {
	if (empty())
		return -1;
	Node *poped;
	int poped_val;
	if (dq->head == dq->tail) {
		poped = dq->head;
		dq->head = dq->tail = 0;
	} else {
		poped = dq->head;
		dq->head = dq->head->next;
		dq->head->prev = 0;
	}
	poped_val = poped->val;
	free(poped);
	dq->sz_--;
	return poped_val;
}

int pop_back() {
	if (empty())
		return -1;
	Node *poped;
	int poped_val;
	if (dq->head == dq->tail) {
		poped = dq->head;
		dq->head = dq->tail = 0;
	} else {
		poped = dq->tail;
		dq->tail = dq->tail->prev;
		dq->tail->next = 0;
	}
	poped_val = poped->val;
	free(poped);
	dq->sz_--;
	return poped_val;
}

int size() {
	return (dq->sz_);
}

int empty() {
	return (!dq->sz_);
}

int front() {
	if (empty())
		return -1;
	return dq->head->val;
}

int back() {
	if (empty())
		return -1;
	return dq->tail->val;
}