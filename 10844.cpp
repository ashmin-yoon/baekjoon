#include <iostream>
using namespace std;
const int INDEX_MAX = 101;
int dp[101][10] = { {0, }, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, };
int N;

int main()
{

	for (int i = 2; i < INDEX_MAX; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			switch(j)
			{
				case 0:
					dp[i][j] = dp[i-1][j+1];
					break;
				case 1: case 2: case 3: case 4: 
				case 5: case 6: case 7: case 8: 
					dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
					break;
				case 9:
				 	dp[i][j] = dp[i-1][j-1];
					break;
			}
			dp[i][j] %= 1000000000;
		}
	}

	cin >> N;
	int ans = 0;

	// 0으로 시작하는 것은 제외
	for (int i = 1; i < 10; i++) {
		ans = (ans + dp[N][i]) % 1000000000;
	}

	cout << ans;

	return 0;
}
