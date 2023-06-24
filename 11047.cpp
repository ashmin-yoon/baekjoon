#include <iostream>
#include <queue>
using namespace std;

// 문제 조건
// 동전은 이전 동전의 배수

int N, K;
int coin[10];

void Input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}
}

int main() {
	Input();

	int ans = 0;

	// 가치 큰 동전부터
	int remain = K;
	for (int i = N - 1; i >= 0; i--) {
		int share = remain / coin[i]; // 몫
		remain %= coin[i]; // 나머지
		ans += share;
	}

	cout << ans;

	return 0;
}
