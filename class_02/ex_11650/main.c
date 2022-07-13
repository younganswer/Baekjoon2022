#include <stdio.h>
#include <stdlib.h>

typedef struct _Coordinate {
	int x, y;
} Coordinate;

size_t N;
Coordinate **coordinates;

int init();
void solve();
int cmp(const void *, const void *);
int free_all();

int main() {
	if (init()) {
		solve();
		free_all();
	}
	return 0;
} // end of main

int init() {
	scanf("%zd", &N);
	coordinates = (Coordinate **) malloc(sizeof(Coordinate *) * N);
	if (!coordinates)
		return 0;
	for (size_t i=0; i<N; i++) {
		coordinates[i] = 0;
		Coordinate *coordinate = (Coordinate *) malloc(sizeof(Coordinate));
		if (!coordinate)
			return (!free_all());
		scanf("%d %d", &(coordinate->x), &(coordinate->y));
		coordinates[i] = coordinate;
	}
	return 1;
}

void solve() {
	qsort(coordinates, N, sizeof(coordinates[0]), cmp);
	for (size_t i=0; i<N; i++) {
		printf("%d %d\n", coordinates[i]->x, coordinates[i]->y);
	}
	return;
}

int cmp(const void *coordinate1, const void *coordinate2) {
	Coordinate *c1 = *(Coordinate **)coordinate1;
	Coordinate *c2 = *(Coordinate **)coordinate2;
	if (c1->x - c2->x)
		return (c1->x - c2->x);
	return (c1->y - c2->y);
}

int free_all() {
	for (size_t i=0; (coordinates[i] && i<N); i++) {
		free(coordinates[i]);
	}
	free(coordinates);
	return 1;
}