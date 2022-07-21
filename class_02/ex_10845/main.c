#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
	int val;
	struct _Node *next;
} Node;

typedef struct _Queue {
	size_t sz_;
	Node *head;
} Queue;

int N;
Queue *queue;

int init();
void solve();
void destroy();

Node *init_node(int);
Node *get_last();

int push_back(int);
int pop_front();
int size();
int is_empty();
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
	queue = (Queue *) malloc(sizeof(Queue));
	if (!queue)
		return 0;
	queue->sz_ = 0;
	queue->head = 0;
	return 1;
}

void solve() {
	char command[6];
	int num;
	while (N--) {
		scanf("%s", command);
		if (!strcmp(command, "push")) {
			scanf("%d", &num);
			if (!push_back(num)) {
				printf("Error: Fail to push.\n");
				return;
			}
		}
		else if (!strcmp(command, "pop"))
			printf("%d\n", pop_front());
		else if (!strcmp(command, "size"))
			printf("%d\n", size());
		else if (!strcmp(command, "empty"))
			printf("%d\n", is_empty());
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
	Node *tmp = queue->head;
	Node *to_del;
	while (tmp) {
		to_del = tmp;
		tmp = tmp->next;
		free(to_del);
	}
	free(queue);
	return;
}

Node *init_node(int num) {
	Node *ret = (Node *) malloc(sizeof(Node));
	if (!ret)
		return 0;
	ret->val = num;
	ret->next = 0;
	return ret;
}

Node *get_last() {
	Node *last = queue->head;
	if (!last->next)
		return last;
	while (last->next)
		last = last->next;
	return last;
}

int push_back(int num) {
	Node *to_insert = init_node(num);
	if (!to_insert)
		return 0;
	if (is_empty())
		queue->head = to_insert;
	else {
		Node *last = get_last();
		last->next = to_insert;
	}
	queue->sz_++;
	return 1;
}

int pop_front() {
	if (is_empty())
		return -1;
	Node *poped = queue->head;
	int ret = poped->val;
	queue->head = queue->head->next;
	queue->sz_--;
	free(poped);
	return ret;
}

int size() {
	return (queue->sz_);
}

int is_empty() {
	return (!queue->sz_);
}

int front() {
	if (is_empty())
		return -1;
	return (queue->head->val);
}

int back() {
	if (is_empty())
		return -1;
	return (get_last()->val);
}