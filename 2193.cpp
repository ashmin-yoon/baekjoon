#include <iostream>
using namespace std;
const int MAX = 91;
int N;
long long int dp[MAX][2] = { {0, 0}, {1, 1}, };

int main()
{
	cin >> N; // 자리 수

	// 1 자리 수

	for (int i = 2; i < MAX; i++) {
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
		cout << dp[i][1] << endl;
	}

	cout << dp[N][1];


	return 0;
}
