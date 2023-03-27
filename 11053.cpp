#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000;

// 실패 후,
// 해결 방법 보고
// 이해 후 제출
int arr[MAX];
int N;
int dp[MAX];
int ans = 1;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dp[0] = 1; // 첫번째 숫자 = 수열 길이 1

	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[i] <= dp[j])
			{
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}
