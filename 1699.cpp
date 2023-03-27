#include <iostream>
#include <cmath>
using namespace std;
const int MAX_SIZE = 100001;
const int INF = 987654321;

int N;
int dp[MAX_SIZE];

int main() {
	cin >> N;

	dp[0] = 0;
	dp[1] = 1;
	int selected = 1;
	for (int i = 2; i < MAX_SIZE; ++i) 
	{
		dp[i] = INF;
		selected = 1;
		if((int)sqrt(i) * (int)sqrt(i) == i)
		{
			dp[i] = 1;
			continue;
		}

		while(selected * selected <= i)
		{
			int tmpCount = 0;
			dp[i] = min(dp[i], 1 + dp[i - selected * selected]);
			++selected;
		}
	}

	cout << dp[N];

	return 0;
}
