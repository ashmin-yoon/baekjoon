#include <iostream>
#include <cmath>
using namespace std;
const int MAX_SIZE = 10000;

int N;
int wine[MAX_SIZE];
int dp[MAX_SIZE][2];
int ans;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> wine[i];
	}


	dp[0][0] = dp[0][1] = wine[0];
	dp[1][0] = wine[0] + wine[1];
	dp[1][1] = wine[1];

	ans = max(dp[1][0], dp[1][1]);

	for (int i = 2; i < N; i++)
	{
		// 이전 선택
		// 현재 와인 선택 + 이이전, 선택X + 이전
		dp[i][0] = max(wine[i] + dp[i-1][1], dp[i-1][0]);

		// 이이전을 선택
		dp[i][1] = wine[i] + max(dp[i-2][0], dp[i-2][1]);
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}
	
	cout << ans;
	return 0;
}
