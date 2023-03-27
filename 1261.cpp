#include <iostream>
#include <queue>
using namespace std;
const int MAX_SIZE = 101;

int N;
int M;

int board[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

typedef struct S{
	int y;
	int x;
	int cost;
	S() {}
	S(int y, int x, int cost) : y(y), x(x), cost(cost) {}

	bool operator()(S a, S b) {
		return a.cost > b.cost;
	}
}S;

int dy[4] = {-1, 0, 1, 0 };
int dx[4] = {0, 1, 0, -1 };

int main() {
	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &board[i][j]);
		}
	}

	// 1, 1 -> 0, 0 시작 지점 변경
	// N, M -> N-1, M-1 도착 지점 변경
	// 좌표, 부셔야할 벽 개수
	priority_queue<S, vector<S>, S> pq;

	pq.push(S(0, 0, 0));

	while(!pq.empty())
	{
		int y = pq.top().y;
		int x = pq.top().x;
		int cost = pq.top().cost;
		pq.pop();

		if (visited[y][x]) continue;
		visited[y][x] = true;
		// cout << y << " " << x << " " << cost << "\n";

		if (y == N - 1 && x == M - 1)
		{
			cout << cost << "\n";
			break;
		}

		for (int direction = 0; direction < 4; direction++)
		{
			int nextY = y + dy[direction];
			int nextX = x + dx[direction];

			if (nextY < 0 || nextY >= N) continue; // 범위
			if (nextX < 0 || nextX >= M) continue; // 범위
			if (visited[nextY][nextX]) continue; // 방문

			if (board[nextY][nextX])
				pq.push(S(nextY, nextX, cost + 1)); // 벽 있음
			else
				pq.push(S(nextY, nextX, cost)); // 벽 없음
		}
	}


	return 0;
}
