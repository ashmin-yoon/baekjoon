#include <iostream>
#include <queue>
using namespace std;
const int MAX_SIZE = 1001;

const int WALL = 1;
const int SPACE = 0;

int N;
int M;
int K;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int board[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][11];

typedef struct Data {
	int y;
	int x;
	int cnt;
	int break_cnt;

	Data(int y, int x, int cnt, int break_cnt) :
		y(y), x(x), cnt(cnt), break_cnt(break_cnt) {}
}Data;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			board[i][j + 1] = str[j] - '0';
		}
	}
}

bool OutOfRange(int y, int x) {
	if (y < 1 || y > N) return true;
	if (x < 1 || x > M) return true;
	return false;
}

int BFS() {

	queue<Data> q;

	// y, x, cnt, break_cnt
	q.push(Data(1, 1, 1, 0));
	visited[1][1][0] = true;

	// 시간 초과 해결 방법
	// 이전 위치 기억
	// 해당 위치로 이동 x

	while(!q.empty()) 
	{
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		int break_cnt = q.front().break_cnt;
		q.pop();
		//cout << y << ", " << x << ", cnt = " << cnt << ", break_cnt = " << break_cnt << endl;

		if (y == N && x == M){
			return cnt;
		}

		for (int i = 0; i < 4; i++) 
		{
			int next_y = y + dy[i];
			int next_x = x + dx[i];

			if (OutOfRange(next_y, next_x)) continue;
			if (visited[next_y][next_x][break_cnt]) continue;
			if (board[next_y][next_x] == WALL) { // 벽일 때
				// 부술 수 있을 때 && 방문 안했을 때
				// 시간 초과 원인 - 벽을 부술 때 visited 체크를 안했음.
				if (break_cnt < K && !visited[next_y][next_x][break_cnt + 1]) {
					visited[next_y][next_x][break_cnt + 1] = true;
					q.push(Data(next_y, next_x, cnt + 1, break_cnt + 1));
				}
				continue;
			}
			// 벽이 아닐 때
			visited[next_y][next_x][break_cnt] = true;
			q.push(Data(next_y, next_x, cnt + 1, break_cnt));
		}

	}

	return -1;

}



int main() {
	FastIO();
	Input();

	cout << BFS();

	return 0;
}
