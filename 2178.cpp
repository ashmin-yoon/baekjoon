#include <iostream>
#include <queue>
using namespace std;
const int MAX_SIZE = 100;

int N, M;
bool board[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int cnt[MAX_SIZE][MAX_SIZE];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};


void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> M;
	
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			board[i][j] = str[j] - '0';
		}
	}
}

bool OutOfRange(int y, int x) {
	if (y < 0 || y >= N) return true;
	if (x < 0 || x >= M) return true;
	return false;
}

void Solution() {
	int y = 0;
	int x = 0;

	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	cnt[y][x] = 1;

	while(!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		if (y == N - 1 && x == M - 1)
			break;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (OutOfRange(ny, nx) || board[ny][nx] == false) continue;
			if (visited[ny][nx]) continue;

			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
			cnt[ny][nx] = cnt[y][x] + 1;
		}
	}
}

int main() {
	FastIO();
	Input();
	Solution();
	cout << cnt[N - 1][M - 1];

	return 0;
}
