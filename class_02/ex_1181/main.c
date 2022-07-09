#include <stdio.h>
#include <stdlib.h>

typedef struct HEAP {
	size_t sz_;
	char **strs;
} Heap;

int N;
Heap *heap;

int init();
void solve();
void insert(const char *);
void print_heap();
void heapify(int);
int is_duplicated(const char *);
void my_swap(char **, char **);
char *my_strdup(const char *);
int my_strcmp(const char *, const char *);
size_t my_strlen(const char *);

int main() {
	if (init())
		solve();
	return 0;
} // end of main

int init() {
	scanf("%d", &N);
	heap = (Heap *) malloc(sizeof(Heap));
	if (!heap)
		return 0;
	heap->sz_ = 0;
	heap->strs = (char **) malloc(sizeof(char *) * (N + 1));
	return 1;
}

void solve() {
	char str[51];
	while (N--) {
		scanf("%s\n", str);
		if (is_duplicated(str))
			continue;
		insert(str);
	}
	print_heap();
	return;
}

void insert(const char *str) {
	heap->strs[++heap->sz_] = my_strdup(str);
	int cur = heap->sz_;
	int par = cur / 2;
	while (0 < par && 0 < my_strcmp(heap->strs[par], heap->strs[cur])) {
		my_swap(&heap->strs[par], &heap->strs[cur]);
		cur = par;
		par = cur / 2;
	}
	return;
}

void print_heap() {
	while (heap->sz_) {
		printf("%s\n", heap->strs[1]);
		my_swap(&heap->strs[1], &heap->strs[heap->sz_]);
		free(heap->strs[heap->sz_--]);
		if (!heap->sz_)
			break;
		heapify(1);
	}
	free(heap->strs);
	free(heap);
	return;
}

void heapify(int cur) {
	size_t left_child = cur * 2;
	size_t right_child = left_child + 1;
	if (heap->sz_ < left_child)
		return;
	if (heap->sz_ < right_child) {
		if (0 < my_strcmp(heap->strs[cur], heap->strs[left_child]))
			my_swap(&heap->strs[cur], &heap->strs[left_child]);
		return;
	}
	int child = (my_strcmp(heap->strs[left_child], heap->strs[right_child]) < 0) ? left_child : right_child;
	if (my_strcmp(heap->strs[cur], heap->strs[child]) < 0)
		return;
	my_swap(&heap->strs[cur], &heap->strs[child]);
	heapify(child);
	return;
}

void my_swap(char **strs1, char **strs2) {
	char *tmp = *strs1;
	*strs1 = *strs2;
	*strs2 = tmp;
	return;
}

char *my_strdup(const char *str) {
	size_t len = my_strlen(str);
	size_t i;
	char *res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return 0;
	for (i=0; i<len; i++) {
		res[i] = str[i];
	}
	res[i] = '\0';
	return res;
}

int is_duplicated(const char *str) {
	for (size_t i=1; i<=heap->sz_; i++) {
		if (!my_strcmp(heap->strs[i], str))
			return 1;
	}
	return 0;
}

int my_strcmp(const char *s1, const char *s2) {
	size_t s1_len = my_strlen(s1);
	size_t s2_len = my_strlen(s2);

	if (s1_len - s2_len)
		return (s1_len - s2_len);
	while (*s1 || *s2) {
		if (*s1 - *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return 0;
}

size_t my_strlen(const char *str) {
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}