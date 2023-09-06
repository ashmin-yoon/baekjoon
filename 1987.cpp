#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 21;

int R, C;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

// 시간 단축 참고
// https://www.acmicpc.net/source/26508302

char board[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int ans = 0;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> board[i][j];
		}
	}
}

void Init() {
	memset(visited, 0, sizeof(visited));
	ans = 0;
}

bool OutOfRange(int y, int x) {
	if (y < 1 || y > R) return true;
	if (x < 1 || x > C) return true;
	return false;
}

void Dfs(int y, int x, int count, int used) {
	// 방문
	if (visited[y][x] == used)
		return;
	visited[y][x] = used;
	ans = max(ans, count);

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (OutOfRange(ny, nx)) continue;
		if (used & (1 << (board[ny][nx] - 'A'))) continue;
		Dfs(ny, nx, count + 1, used | (1 << (board[ny][nx] - 'A')));
	}
}

void Solution() {
	Dfs(1, 1, 1, 1 << (board[1][1] - 'A'));
}

int main() {
	FastIO();
	Init();
	Input();
	Solution();
	cout << ans;

	return 0;
}
