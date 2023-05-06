#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 101;

long long dp[MAX_SIZE][3];
long long buff[MAX_SIZE];

// 최대한 고민해서
// 힌트는 최소한으로만 봄

int N;

int main() {
	cin >> N;

	// 초기값
	dp[1][0] = 1;

	// [][idx]
	// idx 0 단순 A 추가
	// idx 1 Ctrl - A, C, V
	// idx 2 Ctrl - V (buff)

	for (int i = 2; i < MAX_SIZE; i++) {
		buff[i] = max(dp[i-2][0], max(dp[i-2][1], dp[i-2][2])); // Ctrl - A, C

		dp[i][0] = 1 + max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2])); // 단순 A 추가
		dp[i][1] = 2 * buff[i-1]; // Ctrl-(a, c, v)

		// 이 부분이 많이 헷갈림
		// Ctrl-(a, c, v);
		// Ctrl-(a, c, v, v);
		// Ctrl-(a, c, v, v, v);
		dp[i][2] = max(dp[i][1], max(3 * buff[i - 2], 4 * buff[i-3]));
	}


	cout << max(dp[N][0], max(dp[N][1], dp[N][2]));

	return 0;
}
