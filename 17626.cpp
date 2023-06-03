#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX_SIZE = 50001;
const int INF = 987654321;

int N;
int dp[MAX_SIZE];

// 다른 사람 참고

void Init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		dp[i] = INF;
	}
}

int main() {

	Init();
	cin >> N;

	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= (int)sqrt(i); k++) {
			dp[i] = min(dp[i], dp[i - k*k] + 1);
		}
	}

	cout << dp[N];

	return 0;
}
