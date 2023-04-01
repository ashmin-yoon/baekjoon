#include <iostream>
#include <queue>
using namespace std;
const int MAX_SIZE = 1001;
const int WALL = 1;
const int SPACE = 0;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool visited[2][MAX_SIZE][MAX_SIZE]; // 부순 경우, 아닌 경우 구분

int N, M;
char board[MAX_SIZE][MAX_SIZE];

typedef struct Data {
	int y;
	int x;
	int cnt;
	bool isBreakable;
	Data(int y, int x, int cnt, bool isBreakable) {
		this->y = y;
		this->x = x;
		this->cnt = cnt;
		this->isBreakable= isBreakable;
	}
}Data;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> M;

	// 주의 [1, N], [1, M];
	for (int i = 1; i <= N; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < M; j++)
		{
			board[i][j + 1] = line[j] - '0';
		}
	}
}

// 범위 확인
bool OutOfRange(int y, int x) {
	// [1, N], [1, M];
	if (y < 1 || y > N) return true;
	if (x < 1 || x > M) return true;
	return false;
}

void PrintBoard() {
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << (int)board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	FastIO();
	Input();

	queue<Data> q;
	q.push(Data(1, 1, 1, true));


	int ans = -1;
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		bool isBreakable = q.front().isBreakable;
		q.pop();

		// 방문 확인 및 방문
		if (visited[isBreakable][y][x]) continue;
		visited[isBreakable][y][x] = true;

		//cout << "(" << y << ", " << x << ") cnt = " << cnt << ", isBreakable = " << isBreakable << endl;


		// 정답 확인
		if (y == N && x == M)
		{
			ans = cnt;
			break;
		}

		// 방향 체크
		for (int i = 0; i < 4; i++)
		{
			int nextY = y + dy[i];
			int nextX = x + dx[i];
			//cout << "nextY = " << nextY << ", nextX = " << nextX << endl;

			if (OutOfRange(nextY, nextX)) continue;
			if (visited[isBreakable][nextY][nextX]) continue;
			// 벽
			if (board[nextY][nextX] == WALL)
			{
				if (isBreakable)  // 부수기 가능
				{
					q.push(Data(nextY, nextX, cnt + 1, false)); // 더이상 못 부숨
				}

				continue;	
			}

			q.push(Data(nextY, nextX, cnt + 1, isBreakable));
		}
	}


	cout << ans;

	return 0;
}
