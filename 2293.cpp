#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 10001;

int N;
int K;
vector<int> coin;
int dp[MAX_SIZE];

// dp 골드 문제는 아직 감이 잘 안 잡힌 상태
// 문제 풀면서 여러 유형 익히기

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> K;
	int money;
	for (int i = 0; i < N; i++) {
		cin >> money;
		coin.push_back(money);
	}

	sort(coin.begin(), coin.end());
}

int Solution() {

	dp[0] = 1;

	// 동전들 순회하며 만들어가기
	for (int i = 0; i < N; i++) {
		for (int j = coin[i]; j <= K; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}

	return dp[K];
}


int main() {
	FastIO();
	Input();

	cout << Solution();

	return 0;
}
