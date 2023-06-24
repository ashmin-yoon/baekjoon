#include <iostream>
#include <queue>
using namespace std;
const int MAX_SIZE = 600;
const char WALL = 'X';
const char PERSON = 'P';

int N, M;
int start_y, start_x; 

char board[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool OutOfRange(int y, int x) {
	if (y < 0 || y >= N) return true;
	if (x < 0 || x >= M) return true;
	return false;
}

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			// 자신 위치
			if (board[i][j] == 'I') {
				start_y = i;
				start_x = j;
			}
		}
	}
}

int Solution() {
	int y = start_y;
	int x = start_x;
	int meeting_cnt = 0;

	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (OutOfRange(ny, nx)) continue;
			if (visited[ny][nx]) continue;
			if (board[ny][nx] == WALL) continue;

			visited[ny][nx] = true;
			q.push(make_pair(ny, nx));
			if (board[ny][nx] == PERSON)
				meeting_cnt++;
		}
	}

	return meeting_cnt;
}

int main() {
	FastIO();
	Input();

	int meeting_cnt =  Solution();

	if (meeting_cnt == 0) {
		cout << "TT";
	}
	else {
		cout << meeting_cnt;
	}

	return 0;
}
