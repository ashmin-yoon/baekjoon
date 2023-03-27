#include <iostream>

using namespace std;
const int MAX_SIZE = 100001;
const int MOD = 9901;

enum {
	NONE,
	LEFT,
	RIGHT
};

int N;
// [][none, left, right]
int dp[MAX_SIZE][3];

int main()
{
	cin >> N;	


	dp[1][0] = dp[1][1] = dp[1][2] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i][LEFT] = (dp[i-1][RIGHT] + dp[i-1][NONE]) % MOD;
		dp[i][RIGHT] = (dp[i-1][LEFT] + dp[i-1][NONE]) % MOD;

		dp[i][NONE] = (dp[i-1][NONE] + dp[i-1][LEFT]) % MOD;
		dp[i][NONE] += dp[i-1][RIGHT];
		dp[i][NONE] %= MOD;

	}

	int ans = dp[N][NONE];
	ans = (ans + dp[N][LEFT]) % MOD;
	ans = (ans + dp[N][RIGHT]) % MOD;
	cout << ans;
	
	return 0;
}
