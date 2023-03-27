#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 10;

int N, M, K;
int map[MAX][MAX];
int pickValue[MAX];
bool visit[MAX][MAX];

int ans = -987654321;

bool OutOfIndex(int r, int c) {
	if (r < 0 || r >= N)
		return true;
	if (c < 0 || c >= M)
		return true;
	return false;
}

void Solution(int r, int c, int count)
{
	// 범위 검사
	if (OutOfIndex(r, c)) {
		return;
	}

	// (r, c) 왼쪽이나 위에 있으면 return 시키기

	bool left = false;
	bool up = false;
	if (r > 0)
		up = visit[r-1][c];
	if (c > 0)
		left = visit[r][c-1];
	if (left || up) {
		return;
	}

	// 중단점
	if (count == K)
	{
		int sum = 0;
		for (int i = 0; i < K; i++)
		{
			sum += pickValue[i];
		}

		ans = max(ans, sum);
		return;
	}


	for (int try_c= (r * M) + c; try_c < N * M; try_c++) {
		// 행 번호 = c / N
		// 열 번호 = c % M
		int next_r = try_c / M;
		int next_c = try_c % M;

		if (visit[next_r][next_c]) {
			continue;
		}

		visit[next_r][next_c] = true;
		pickValue[count] = map[next_r][next_c];
		Solution(next_r, next_c, count+1);
		visit[next_r][next_c] = false;
	}
}

int main()
{
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	Solution(0, 0, 0);
	cout << ans << endl;

	return 0;
}
