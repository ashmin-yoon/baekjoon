#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 100+2;

int N, M;
int arr[MAX_SIZE][MAX_SIZE];

// 바라보는 방향6
// 각 면에서 보이는 개수만 count

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}

	int right = 0;
	int left = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (arr[i][j] - arr[i][j+1] > 0)
				right += arr[i][j] - arr[i][j+1];

			if (arr[i][j] - arr[i][j-1] > 0)
				left += arr[i][j] - arr[i][j-1];
		}
	}

	int front = 0;
	int back = 0;
	for (int j = 1; j <= M; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			if (arr[i][j] - arr[i+1][j] > 0)
				front += arr[i][j] - arr[i+1][j];

			if (arr[i][j] - arr[i-1][j] > 0)
				back += arr[i][j] - arr[i-1][j];
		}
	}
	int ans = 0;
	ans += N*M * 2; // 아래, 위
	ans += front;
	ans += back;
	ans += left;
	ans += right;
	cout << ans;

	return 0;
}
