#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 20;


int N; // 개수
int S; // 목표
int ans = 0;

vector<int> nums;
int selected[MAX];
bool visited[MAX];

void dfs(int picked, int count, int sum) {
	if (S == sum) {
		ans++;
	}

	if (count == N) {
		return;
	}

	for (int i = picked; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		dfs(i, count + 1, sum + nums[i]);
		visited[i] = false;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> S;	

	nums.reserve(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	// 정렬
	sort(nums.begin(), nums.end());


	/*
	int T = 1 << N;
	// if N == 4
	// 0 0 0 0 <= t < 1 0 0 0 0
	for (int tc = 1; tc < T; tc++) {
		int sum = 0; 
		for (int i = 0; i < N; i++) {
			if (tc & (1 << i))
				sum += nums[i];
		}

		if (S == sum)
			ans++;
	}
	// 반복문으로 해결했을 때와 재귀로 해결했을 때
	// 속도차이가 있음
	// 재귀가 더 빠른 모습을 보였는데
	// 어떤점에서 속도 차이가 나는지 정확히 모르겠음
	// 둘 다 전체 경우의 수를 훑는 것인데..
	*/

	dfs(0, 0, 0);
	if (S == 0 && ans > 0) ans--;
	cout << ans << '\n';
}
