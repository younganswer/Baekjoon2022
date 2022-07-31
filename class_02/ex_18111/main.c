#include <stdio.h>

#define MAX 500

int N, M, B;
int map[MAX][MAX];

void init();
void solve();
int get_cost(int);

int main() {
	init();
	solve();
	return 0;
} // end of main

void init() {
	scanf("%d %d %d", &N, &M, &B);
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	return;
}

void solve() {
	int time_res=2147483647, height_res, cur_time;
	for (int cur_height=0; cur_height<=256; cur_height++) {
		cur_time = get_cost(cur_height);
		if (cur_time == -1)
			break;
		if (cur_time <= time_res) {
			time_res = cur_time;
			height_res = cur_height;
		}
	}
	printf("%d %d\n", time_res, height_res);
	return;
}

int get_cost(int height) {
	int res=0, remain=B;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (height < map[i][j]) {
				res += 2 * (map[i][j] - height);
				remain += (map[i][j] - height);
			}				
			else if (map[i][j] < height) {
				res += (height - map[i][j]);
				remain -= (height - map[i][j]);
			}
		}
	}
	if (remain < 0)
		res = -1;
	return res;
}