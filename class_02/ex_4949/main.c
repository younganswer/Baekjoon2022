#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct _Node {
	char c;
	struct _Node *next;
} Node;

typedef struct _List {
	size_t sz_;
	Node *head;
} List;

char str[MAX+1];
List *list;

int init();
void solve();
void destroy();

int push_back(char);
char pop_back();

Node *init_node(char);

int main() {
	// init이 정상적으로 되었을때, solve, destroy실행
	while (init()) {
		solve();
		destroy();
	}
	return 0;
} // end of main

int init() {
	// 개행문자까지 input을 읽어들여서, 개행문자를 제외한 나머지 문자들을 str에 저장함.
	fgets(str, MAX+2, stdin);
	// 종료 조건
	if (str[0] == '.')
		return 0;
	list = (List *) malloc(sizeof(List));
	if (!list)
		return 0;
	list->sz_ = 0;
	list->head = 0;
	return 1;
}

void solve() {
	char *tmp = str;
	while (*tmp != '.') {
		if (*tmp == '(' || *tmp == '[') {
			// 정상적으로 push가 되었는지 확인
			if (!push_back(*tmp))
				return;
		}
		else if (*tmp == ')' || *tmp == ']') {
			// list에 '('나 '['가 없다면(list가 비어있다면) 짝이 맞지 않음
			if (!list->sz_) {
				printf("no\n");
				return;
			}
			// list에 node는 존재하나 짝이 맞지 않음
			else {
				char poped = pop_back();
				if ((*tmp == ')' && poped != '(') || (*tmp == ']' && poped != '[')) {
					printf("no\n");
					return;
				}
			}
		}
		tmp++;
	}
	// list에 남은 '('나 '['가 존재함
	if (list->sz_)
		printf("no\n");
	else
		printf("yes\n");
	return;
}

int push_back(char c) {
	// list에 원소가 없을 경우
	if (!list->head) {
		list->head = init_node(c);
		// 정상적으로 노드가 생성되었는지 확인
		if (!list->head)
			return 0;
	}
	// 원소가 존재할 경우
	else {
		Node *tmp = list->head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = init_node(c);
		// 정상적으로 노드가 생성되었는지 확인
		if (!tmp->next)
			return 0;
	}
	list->sz_++;
	return 1;
}

char pop_back() {
	// list에 원소가 없을 경우
	if (!list->head)
		return 0;
	char ret;
	Node *tmp = list->head;
	// list에 원소가 하나일 경우
	if (!tmp->next) {
		ret = tmp->c;
		free(list->head);
		list->sz_--;
		list->head = 0;
		return ret;
	}
	// list에 원소가 2개 이상일 경우
	while (tmp->next->next)
		tmp = tmp->next;
	ret = tmp->next->c;
	free(tmp->next);
	tmp->next = 0;
	list->sz_--;
	return ret;
}

Node *init_node(char c) {
	Node *ret = (Node *) malloc(sizeof(Node));
	if (!ret)
		return 0;
	ret->c = c;
	ret->next = 0;
	return ret;
}

void destroy() {
	Node *tmp;
	Node *to_del;

	tmp = list->head;
	while (tmp) {
		to_del = tmp;
		tmp = tmp->next;
		free(to_del);
	}
	free(list);
	list = 0;
	return;
}