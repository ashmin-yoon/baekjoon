#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 50;

int N, S, M;
int v[MAX_SIZE];
int dp[MAX_SIZE][1001];


void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

bool OutOfRange(int volume) {
	if (volume < 0 || volume > M) 
		return true;
	return false;
}

void Input() {
	cin >> N >> S >> M;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
}

void Init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < 1001; j++) {
			dp[i][j] = -1;
		}
	}
}

// Top down
// 기존 시간 초과 문제
// 구하지 않음 -1, 범위를 벗어남 -1
// 동일하게 초기화를 했기에 중복되서 계산됨
// https://www.acmicpc.net/board/view/2481 참고
int FindMaxVolume(int idx, int volume) {
	if (OutOfRange(volume))
		return -2; // 범위 벗어남

	// 마지막 끝
	if (idx == N) {
		return volume;
	}

	int& ret = dp[idx][volume];

	// 기존에 구함
	if (ret > 0)
		return ret;


	// -1 구하지 않았을 때만 계산 수행
	if (ret == -1) {
		ret = FindMaxVolume(idx + 1, volume + v[idx]);
		ret = max(ret, FindMaxVolume(idx + 1, volume - v[idx]));
	}
	return ret;
}


int main() {
	FastIO();
	Init();
	Input();
	int ans = FindMaxVolume(0, S);
	if (ans < 0)
		ans = -1;
	cout << ans;

	return 0;
}
