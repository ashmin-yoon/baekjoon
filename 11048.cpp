#include <iostream>
using namespace std;
const int MAX_SIZE = 1001;

int N, M;
int board[MAX_SIZE][MAX_SIZE];


void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> M;

	// 범위 [1, N][1, M]
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}
}

int Solution() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			// 상, 좌상, 좌 검사
			int left_up = board[i-1][j-1];
			int up = board[i-1][j];
			int left = board[i][j-1];

			board[i][j] += max(left, max(left_up, up));
		}
	}

	return board[N][M];
}

int main() {
	FastIO();
	Input();

	cout << Solution();

	return 0;
}
