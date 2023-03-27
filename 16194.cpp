#include <iostream>
#include <cmath>
using namespace std;
const int INF = 987654321;

int N;
int dp[10001];
int pack[10001]; // 팩 가격

void BruteForce(int index, int sum) {
	// 
}

int main() 
{
	cin >> N;
	for (int i = 1; i <= N; i++) 
	{
		cin >> pack[i];
	}

	// 초기값
	dp[1] = pack[1];
	for (int i = 2; i <= N; i++) {
		int tmp = INF;

		for (int j = 1; j < (i/2 + 1); j++) {
			tmp = min(tmp, dp[i-j] + dp[j]);
		}
		// 자신의 팩 가격 vs 이전까지의 조합으로 만든 최소 가격
		dp[i] = min(pack[i], tmp);
	}
	cout << dp[N];
	return 0;
}
