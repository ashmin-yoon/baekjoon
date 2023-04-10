#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int MAX_SIZE = 100;
const char R = 'R';
const char G = 'G';
const char B = 'B';
const char W = 'W';  // 특별한 그룹 'R' || 'G'

int N;
char board[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int dy[4] = {-1, 0, 1, 0 };
int dx[4] = {0, 1, 0, -1 };

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

}

void InitVisited() {
	for (int i = 0; i < N; i++) {
		memset(visited[i], false, sizeof(bool) * N);
	}
}


bool OutOfRange(int y, int x) {
	if (y < 0 || y >= N) return true;
	if (x < 0 || x >= N) return true;
	return false;
}



void BfsColor(int y, int x, char color) {
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));

	visited[y][x] = true;

	while(!q.empty()) 
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];

			if (OutOfRange(next_y, next_x)) continue;
			if (visited[next_y][next_x]) continue;
			if (color != W && board[next_y][next_x] != color)
				continue; // 다른 색상
			if (color == W && board[next_y][next_x] == B)
				continue; // R 또는 G 가 아닐 때

			// 방문
			q.push(make_pair(next_y, next_x));
			visited[next_y][next_x] = true;

		}

	}


}

int GetOrdinaryGroupCount() {
	InitVisited();

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				BfsColor(i, j, board[i][j]);
				cnt++;
			}
		}
	}

	return cnt;
}

int GetColorWeaknessGroupCount() {
	InitVisited();

	int cnt = 0;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			if (visited[i][j]) continue;
			if (board[i][j] == B) // B Bfs
				BfsColor(i, j, B);
			else
				BfsColor(i, j, W); // R, G Bfs
			cnt++;
		}
	}

	return cnt;

}

int main() {
	FastIO();
	Input();

	cout << GetOrdinaryGroupCount() << " ";
	cout << GetColorWeaknessGroupCount();

	return 0;
}
