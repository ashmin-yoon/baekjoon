#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 50;

int is_shark[MAX_SIZE][MAX_SIZE];

int N, M;
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool visited[MAX_SIZE][MAX_SIZE];

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
			cin >> is_shark[i][j];
		}
	}
}

int BfsFindSafetyDistance(int y, int x) {

	queue<pair<int, int> > q;
	queue<int> cnt_q;
	q.push(make_pair(y, x));
	cnt_q.push(0);

	int cnt = 0;

	while(!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		cnt = cnt_q.front();
		q.pop();
		cnt_q.pop();

		if (is_shark[y][x])
			return cnt;
		visited[y][x] = true;

		// 이동
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (OutOfRange(ny, nx)) continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = true;
			q.push(make_pair(ny, nx));
			cnt_q.push(cnt + 1);
		}

	}

	return cnt;
}

void InitVisited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}
}

int Solution() {
	int max_dist = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 상어가 아닐 때
			if (!is_shark[i][j])
			{
				InitVisited();
				max_dist = max(max_dist, BfsFindSafetyDistance(i, j));
			}
		}
	}

	return max_dist;
}

int main() {

	FastIO();
	Input();
	cout << Solution();

	return 0;
}
