#include <iostream>
using namespace std;
const int MAX_SIZE = 5001;
const int MOD = 1000000007;

unsigned long long dp[MAX_SIZE];

// 시간이 너무 오래걸려서 풀이 봄
// https://week-year.tistory.com/172

void SetDp() {
	dp[0] = 1;
	dp[2] = 1;
	dp[4] = 2;

	// ()ㅁ
	// (ㅁ)ㅁ
	// (ㅁ)
	for (int i = 6; i < MAX_SIZE; i+=2) {
		for (int j = 2; i - j >= 0; j+=2) {
			dp[i] += dp[j - 2] * dp[i - j];
			dp[i] %= MOD;
		}
	}
}

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

int main() {
	FastIO();
	SetDp();

	int T;
	int n;
	cin >> T;

	while(T--) {
		cin >> n;
		cout << dp[n] << "\n";
	}

	return 0;
}
