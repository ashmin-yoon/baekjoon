#include <iostream>
using namespace std;
const int MOD = 1000000009;
const int MAX_SIZE = 1000001;

int n;
int T;

int dp[MAX_SIZE];

int main() 
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> T;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < MAX_SIZE; i++)
	{
		dp[i] = (dp[i-1] + dp[i-2]) % MOD;
		dp[i] = (dp[i] + dp[i-3]) % MOD;
	}

	while(T--)
	{
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}

