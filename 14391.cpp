#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int MAX = 4;
const int MINUS_INF = -987654321;

int N; 	// 세로 크기 Row
int M;	// 가로 크기 Col
int ROW;
int COL;
char value[MAX][MAX];
int ans;

// 여러 블로그 해설 글 참고

int main() {
	cin >> N >> M;
	ROW = N;
	COL = M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> value[i][j];
		}
	}

	// 각 칸은 0, 1 비트 값을 가지며
	// 0이면 가로로 이어진 부분
	// 1이면 세로로 이어진 부분
	// 각 계산해서 더해본다.

	int sum = 0;
	int bitIndex = 0;
	// 전체 경우의 수
	for (int tc = 0; tc < (1 << ROW * COL); tc++) 
	{
		// 가로 합계
		int rowSum = 0;
		for (int r = 0; r < ROW; r++)
		{
			// 0, 1, 2, 3
			// 4, 5, 6, 7
			int partialRowSum = 0;
			for (int c = 0; c < COL; c++)
			{
				bitIndex = r * COL + c;

				if ((tc & 1 << bitIndex) == 0)
				{
					partialRowSum *= 10; // 자리 수 증가
					partialRowSum += value[r][c] - '0';
				}
				else 
				{
					rowSum += partialRowSum;
					partialRowSum = 0;
				}
			}
			rowSum += partialRowSum;
		}

		// 세로 합계
		int colSum = 0;
		for (int c = 0; c < COL; c++)
		{
			// 0, 4, 8, 12
			// 1, 5, 9, 13
			int partialColSum = 0;
			for (int r = 0; r < ROW; r++)
			{
				bitIndex = r * COL + c;

				if ((tc & 1 << bitIndex) != 0)
				{
					partialColSum *= 10; // 자리 수 증가
					partialColSum += value[r][c] - '0';
				}
				else 
				{
					colSum += partialColSum;
					partialColSum = 0;
				}
			}
			colSum += partialColSum;
		}

		sum = rowSum + colSum;
		ans = max(ans, sum);
		//cout << sum << endl;
	}

	cout << ans;
		

	return 0;
}
