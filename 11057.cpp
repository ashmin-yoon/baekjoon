#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 10007;

int N;
int dp[10];

int main()
{
	for (int i = 0; i < 10; i++)
	{
		dp[i] = 1;
	}

	cin >> N;

	for (int i = 1; i < N; i++)
	{
		for (int j = 8; j >= 0; j--)
		{
			dp[j] = (dp[j] + dp[j+1]) % MOD;
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans += dp[i];	
	}
	ans %= MOD;

	cout << ans;

	return 0;
}
