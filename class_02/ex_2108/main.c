#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>

#define MAX 500000

int N;

// 숫자들을 저장할 배열
int nums[MAX];

// 무슨 숫자가 몇 번 나왔는지 체크할 배열
// -4000 ~ 4000 => 0 ~ 8001
int cnt[8001];

// 산술평균을 구하기 위한 합
double sum;

// 제일 높은 빈도 수 체크
int cnt_max;
// 제일 높은 빈도 수를 가진 숫자가 무엇인지 저장.
int cnt_max_num;

void init();
void solve();
int cmp(const void *, const void *);

int main() {
	init();
	solve();
	return 0;
} // end of main

void init() {
	scanf("%d", &N);
	memset(nums, 0, MAX);
	memset(cnt, 0, 8001);
	sum = 0;
	cnt_max = 0;
	// 나올 수 없는 수로 초기화
	cnt_max_num = 2147483647;
	return;
}

void solve() {
	for (int i=0; i<N; i++) {
		scanf("%d", &nums[i]);
		sum += nums[i];
		cnt[nums[i] + 4000]++;
		if (cnt_max < cnt[nums[i] + 4000])
			cnt_max = cnt[nums[i] + 4000];
	}
	qsort(nums, N, sizeof(int), cmp);
	for (int i=0; i<N; i++) {
		// cnt_max_num이 변경되지 않았다면 패스
		// cnt_max_num과 같은 값이라면 패스
		// cnt_max_num보다 하나 큰 수에서 다시 할당하고 break;
		if (cnt_max_num != 2147483647 && cnt_max_num != nums[i] && cnt_max == cnt[nums[i] + 4000]) {
			cnt_max_num = nums[i];
			break;
		}
		// 최대 빈도 수와 일치할때 cnt_max_num 할당
		if (cnt_max == cnt[nums[i] + 4000])
			cnt_max_num = nums[i];
	}
	// floor((sum / N) + 0.5) => 내림을 이용해 반올림 구현
	printf("%d\n%d\n%d\n%d\n", (int) floor((sum / N) + 0.5), nums[N / 2], cnt_max_num, nums[N-1] - nums[0]);
	return;
}

int cmp(const void *a, const void *b) {
	if (*(int *)a > *(int *)b)
		return 1;
	else if (*(int *)a < *(int *)b)
		return -1;
	return 0;
}