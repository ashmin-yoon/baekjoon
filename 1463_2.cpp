#include <iostream>
#include <cmath>
const int INF = 987654321;
using namespace std;

int dp[1000001];
int main()
{
	int N;
	cin >> N;

	dp[0] = INF;
	dp[1] = 0;

	int curMin = INF;
	for (int i = 2; i <= N; i++)
	{
		curMin = INF;
		if (i % 3 == 0)
			curMin = min(curMin, dp[i / 3] + 1);
		if (i % 2 == 0)
			curMin = min(curMin, dp[i / 2] + 1);

		dp[i] = min(curMin, dp[i-1] + 1);
	}

	cout << dp[N];


	return 0;
}
