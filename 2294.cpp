#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX_SIZE = 10001;
const int INF = 987654321;

// 문제 해결
// 최초 dp[K] 값 찾으면 답을 출력했다 => 46% 터짐
// 이후 작은 동전의 선택이 더 최적인 답일 수 있음
// 예시 찾기 어려웠음
// 4 35
// 15 9 4 2
// ans = 4 wrong = 5

int N;
int K;
int coin[100];
int dp[MAX_SIZE];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	// 동전 내림차순
	sort(coin, coin + N, cmp);

	// 초기화
	for (int i = 0; i < MAX_SIZE; i++) {
		dp[i] = INF;
	}

	dp[0] = 0;
	bool hasFinded = false;
	for (int i = 0; i < N; i++) {
		for (int j = coin[i]; j <= K; j++) {
			// 이전 값 없음
			if (dp[j - coin[i]] == INF)
				continue;

			// 최솟값 갱신
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
			//cout << "dp[" << j << "] = dp[" << j << " - " << coin[i] << "] + 1" << endl;
			//cout << dp[j] << " = " << dp[j-coin[i]] + 1 << endl;
		}
	}

	if (dp[K] != INF)
		cout << dp[K] << endl;
	else
		cout << -1 << endl;

}
