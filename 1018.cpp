#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 50;

int N;
int M;

int board[MAX_SIZE][MAX_SIZE];
const int BLACK = 0;
const int WHITE = 1;


int ChessBoardPaintingCount(int y, int x) {

	int cnt1 = 0;
	int cnt2 = 0;
	int color1 = BLACK;
	int color2 = WHITE;

	for (int i = y; i < y + 8; i++)
	{
		for (int j = x; j < x + 8; j++)
		{
			if (board[i][j] != color1) cnt1++;
			if (board[i][j] != color2) cnt2++;
			// 다음 색상
			color1 = (color1 + 1) % 2;
			color2 = (color2 + 1) % 2;
		}
		// 첫열 색상은 이전 마지막 칸과 같음
		color1 = (color1 + 1) % 2;
		color2 = (color2 + 1) % 2;
	}

	return min(cnt1, cnt2);

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;

		for (int j = 0; j < M; j++)
		{
			if (line[j] == 'B')
				board[i][j] = BLACK;
			else 
				board[i][j] = WHITE;
		}

	}


	int ans = 987654321;
	// 보드판을 만들 수 있는 시작점만 확인 
	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			ans = min(ans, ChessBoardPaintingCount(i, j));
		}
	}

	cout << ans;

	return 0;
}
