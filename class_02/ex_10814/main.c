#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct MEMBER {
	size_t age;
	char *name;
	size_t id;
} Member;

size_t N;
Member **members;

int init();
void solve();
void free_all();

int my_cmp(const void *, const void *);

Member *init_member(size_t, const char *, size_t);

char *my_strdup(const char *);
size_t my_strlen(const char *);

int main() {
	if (init()) {
		solve();
		free_all();
	}
	return 0;
} // end of main

int init() {
	scanf("%zd", &N);
	members = (Member **) malloc(sizeof(Member *) * N);
	if (!members)
		return 0;
	for (size_t i=0; i<N; i++) {
		size_t age;
		char name[101];
		scanf("%zd %s", &age, name);
		members[i] = init_member(age, name, i);
		if (!members[i])
			return 0;
	}
	return 1;
}

void solve() {
	qsort(members, N, sizeof(members[0]), my_cmp);
	for (size_t i=0; i<N; i++) {
		printf("%zd %s\n", members[i]->age, members[i]->name);
	}
	return;
}

void free_all() {
	for (size_t i=0; i<N; i++) {
		free(members[i]->name);
		free(members[i]);
	}
	free(members);
	return;
}

int my_cmp(const void *member1, const void *member2) {
	Member *m1 = *(Member **) member1;
	Member *m2 = *(Member **) member2;

	if (m1->age - m2->age)
		return (m1->age > m2->age);
	return (m1->id > m2->id);
}

Member *init_member(size_t age, const char *name, size_t id) {
	Member *ret = (Member *) malloc(sizeof(Member));
	if (!ret)
		return 0;
	ret->age = age;
	ret->name = my_strdup(name);
	if (!ret->name)
		return 0;
	ret->id = id;
	return ret;
}

char *my_strdup(const char *str) {
	size_t len = my_strlen(str);

	char *ret = (char *) malloc(sizeof(char) * (len + 1));
	if (!ret)
		return 0;

	size_t i;
	for (i=0; i<len; i++) {
		ret[i] = str[i];
	}
	ret[i] = '\0';
	return ret;
}

size_t my_strlen(const char *str) {
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}