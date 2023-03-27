#include <iostream>
using namespace std;
const int DIVISOR = 1000000000;
const int MAX_SIZE = 201;
int N;
int K;
int dp[MAX_SIZE][MAX_SIZE];


int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> K;

	for (int i = 1; i <= N; i++)
	{
		dp[i][1] = 1;
	}

	for (int j = 1; j <= K; j++)
	{
		dp[0][j] = 1;
	}

	// 행과 열을 그렸을 때
	// [i][j] = sum([0~i][j-1]) 규칙이 있음
	for (int j = 2; j <= K; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % DIVISOR;
		}
	}

	cout << dp[N][K] << '\n';

	return 0;
}
