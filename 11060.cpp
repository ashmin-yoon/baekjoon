#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 1001;
const int INF = 987654321;

int N;
int arr[MAX_SIZE];
int jump_cnt[MAX_SIZE];

// 사용 범위 [1, N]
void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void Init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		jump_cnt[i] = INF;
	}
}

int Solution() {
	jump_cnt[1] = 0; // 시작점 초기화
	for (int i = 1; i <= N; i++) {
		if (jump_cnt[i] == INF) // 더이상 진행 불가
			break;

		// 점프 갱신
		for (int j = 1; j <= arr[i]; j++) {
			jump_cnt[i + j] = min(jump_cnt[i + j], jump_cnt[i] + 1);
		}
	}

	// 정답
	if (jump_cnt[N] == INF)
		return -1;
	return jump_cnt[N];
}

int main() {
	Init();
	Input();
	cout << Solution();

	return 0;
}
