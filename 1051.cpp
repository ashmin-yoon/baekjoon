#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 50;

int N, M;

int arr[MAX_SIZE][MAX_SIZE];
int ans;

int Solve(int start_i, int start_j)
{
	int width = 0;
	int height = 0;
	int rev =  1;

	for (int j = start_j; j < M; j++)
	{
		if (arr[start_i][start_j] != arr[start_i][j])
			continue;
		int value = arr[start_i][start_j];

		width = j - start_j + 1;
		int row = start_i + width - 1;
		if (row >= N) continue;
		if (arr[row][start_j] != value ||
				arr[row][j] != value) 
			continue;
		rev = max(rev, width * width); // 정사각형
	}

	cout << start_i << "\t" << start_j << " = " << rev << "\n";
	return rev;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	
	// 전체 행
	for (int i = 0; i < N; i++)
	{
		// 열
		for (int j = 0; j < M; j++)
		{
			ans = max(ans, Solve(i, j));
		}
	}
	cout << ans;
	return 0;
}
