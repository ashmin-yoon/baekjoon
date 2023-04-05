#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_SIZE = 8;
const char WALL = '#';

char board[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE + 1]; // 몇 번째 이동에서 자리하고 있는지

typedef struct Point {
	int y;
	int x;
	Point(int y, int x) : y(y), x(x) {}
}Point;

int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool OutOfRange(int y, int x) {
	if (y < 0 || y >= MAX_SIZE) return true;
	if (x < 0 || x >= MAX_SIZE) return true;
	return false;
}

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {

	for (int i = 0; i < MAX_SIZE; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < MAX_SIZE; j++)
		{
			board[i][j] = str[j];
		}
	}
}

void PrintBoard() {
	cout << "==================\n";
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}

void MoveDownWall() {
	// 한 칸 아래 이동
	for (int i = 7; i > 0; i--)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			board[i][j] = board[i - 1][j];
		}
	}

	// 첫 줄 초기화
	for (int j = 0; j < MAX_SIZE; j++)
	{
		board[0][j] = '.';
	}

}


int main() {
	FastIO();
	Input();

	// 시작 y = 7, x = 0
	queue<Point> q;
	queue<int> cnt_q;
	q.push(Point(7, 0));
	cnt_q.push(0);

	// 최종적으로 같은 로직인데
	// 기존 코드는 10%에서 틀림

	while(!q.empty())
	{
		int q_size = q.size();
		while(q_size--)
		{
			int y = q.front().y;
			int x = q.front().x;
			int cnt = cnt_q.front();
			q.pop();
			cnt_q.pop();

			//cout << "y = " << y << ", x = " << x << ", cnt = " << cnt << endl;

			// 벽이면 이동 불가
			if (board[y][x] == WALL)
				continue;

			if (y == 0) // 첫 줄 도착
			{
				cout << true;
				return 0;
			}

			// 머무르기
			if (!visited[y][x][cnt + 1]) {
				visited[y][x][cnt + 1] = true;
				q.push(Point(y, x));
				cnt_q.push(cnt + 1);
			}

			// 주변 8칸
			for (int i = 0; i < 8; i++)
			{
				int next_y = y + dy[i];
				int next_x = x + dx[i];

				if (OutOfRange(next_y, next_x)) continue;
				if (board[next_y][next_x] == WALL) continue;
				if (visited[next_y][next_x][cnt + 1]) continue;
				visited[next_y][next_x][cnt + 1] = true;
				q.push(Point(next_y, next_x));
				cnt_q.push(cnt + 1);
			}

		}
		MoveDownWall();
	}

	cout << false;

	return 0;
}
