#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 51;

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
	for (int i = 1; i <= N; i++) {
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


// bottom-up
int FindMaxVolume() {
	for (int i = 0; i < 1001; i++) {
		dp[0][i] = S;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 1001; j++) {
			if (dp[i-1][j] == -1) continue;

			int plus = dp[i-1][j] + v[i];
			if (!OutOfRange(plus)) {
				dp[i][plus] = plus;
			}

			int minus = dp[i-1][j] - v[i];
			if (!OutOfRange(minus)) {
				dp[i][minus] = minus;
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < 1001; i++) {
		ans = max(ans, dp[N][i]);
	}
	return ans;
}

int main() {
	FastIO();
	Init();
	Input();
	cout << FindMaxVolume();

	return 0;
}
