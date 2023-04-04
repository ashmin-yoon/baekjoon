#include <iostream>
#include <queue>
using namespace std;
const int MAX_SIZE = 1001;

int N, M, K;

enum State{
	DAY, NIGHT
};

const int WALL = 1;
const int SPACE = 0;

// [y][x][break_cnt][state]
bool visited[MAX_SIZE][MAX_SIZE][11][2];
int board[MAX_SIZE][MAX_SIZE];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};


typedef struct Data {
	int y;
	int x;
	int cnt;
	int break_cnt;
	State state;

	Data(int y, int x, int cnt,
			int break_cnt, State state) :
		y(y), x(x), cnt(cnt),
		break_cnt(break_cnt), state(state) {}
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
		for (int j = 0; j < str.size(); j++)
		{
			board[i][j+1] = str[j] - '0';
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
	// y, x, cnt, break_cnt, state
	q.push(Data(1, 1, 1, 0, DAY));
	visited[1][1][0][DAY] = true;

	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		int break_cnt = q.front().break_cnt;
		State state = q.front().state;
		q.pop();

		//cout << "y = " << y << ", x = " << x << ", cnt = " << cnt;
		//cout << ", break_cnt = " << break_cnt << ", state = " << state << "\n";
		if (y == N && x == M)
			return cnt;



		// 다음 상태
		State next_state = state == DAY ? NIGHT : DAY;


		// 현재 칸에 머무르기
		if (!visited[y][x][break_cnt][next_state])
		{
			visited[y][x][break_cnt][next_state] = true;
			q.push(Data(y, x, cnt + 1, break_cnt, next_state));
		}

		// 이동
		for (int i = 0; i < 4; i++) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];

			if (OutOfRange(next_y, next_x)) continue;
			if (visited[next_y][next_x][break_cnt][next_state]) continue;
			if (board[next_y][next_x] == WALL) // 벽일 때
			{
				// 현재가 밤
				if (state == NIGHT)
				{
					// 끝
					continue;
				}

				// 현재 낮일 때만 부술 수 있음
				if (break_cnt < K && !visited[next_y][next_x][break_cnt + 1][next_state]) // 부술 수 있다면
				{
					visited[next_y][next_x][break_cnt + 1][next_state] = true;
					q.push(Data(next_y, next_x, cnt + 1, break_cnt + 1, next_state));
				}
				continue;
			}

			// 빈 칸
			visited[next_y][next_x][break_cnt][next_state] = true;
			q.push(Data(next_y, next_x, cnt + 1, break_cnt, next_state));
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
