#include <iostream>
using namespace std;

const int MAX = 100001;
int dp[MAX][3];
// [][0] 시작 1로 만들 수 있는 수
// [][1] 시작 2
// [][2] 시작 3

int main()
{
	// 속도 향상
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int T = 0;
	cin >> T;
	int N = 0;
	int ans = 0;

	dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
	dp[1][0] = 1; dp[1][1] = 0; dp[1][2] = 0;
	dp[2][0] = 0; dp[2][1] = 1; dp[2][2] = 0;
	dp[3][0] = 1; dp[3][1] = 1; dp[3][2] = 1;

	// 특정 숫자를 만드는데
	// [j] j+1로 시작하는 조합 방법 수

	int divisor = 1000000009;
	for (int i = 4; i < MAX; i++)
	{
		dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % divisor;
		dp[i][1] = (dp[i-2][0] + dp[i-2][2]) % divisor;
		dp[i][2] = (dp[i-3][0] + dp[i-3][1]) % divisor;
	}

	while(T--)
	{
		cin >> N;
		ans = (dp[N][0] + dp[N][1]) % divisor;
		ans += dp[N][2];
    ans %= divisor;
		cout << ans << '\n';
	}

	return 0;
}
