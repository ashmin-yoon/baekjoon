#include <iostream>
using namespace std;
const int MAX_SIZE = 10001;

// [number][시작숫자] 
int dp[MAX_SIZE][4];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

// 단순 전체가 아닌
// 시작 숫자 이후의 값들은
// 시작 숫자보다 작거나 같다.
void SetDp() {

	// 초기화
	dp[1][1] = 1;
	dp[2][1] = dp[2][2] = 1;
	dp[3][1] = dp[3][2] = dp[3][3] = 1;

	for (int i = 4; i < MAX_SIZE; i++) {
		dp[i][1] = 1; // 1로 만듬
		dp[i][2] = dp[i-2][2] + dp[i-2][1]; // 2로 시작
		dp[i][3] = dp[i-3][3] + dp[i-3][2] + dp[i-3][1]; // 3으로 시작
	}
}

int main() {
	FastIO();
	SetDp();

	int T, n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
	}

	return 0;
}
