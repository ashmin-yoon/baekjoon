#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 50;
const int INF = 987654321;
const int WALL = 1;
const int VIRUS = 2;

int N, M;
int ans = INF;

int board[MAX_SIZE][MAX_SIZE];
int group_number[MAX_SIZE][MAX_SIZE];
int group_count;
int space_count = 0;

bool visited[MAX_SIZE][MAX_SIZE];

vector<pair<int, int> > virus_pos;
bool selected[11]; // 선택된 바이러스

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};


typedef struct Data {
	int y;
	int x;
	int cnt;
	Data() {}
	Data(int y, int x, int cnt) :
		y(y), x(x), cnt(cnt) {}
}Data;

bool OutOfRange(int y, int x) {
	if (y < 0 || y >= N) return true;
	if (x < 0 || x >= N) return true;
	return false;
}

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	space_count = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == VIRUS) { // 바이러스 놓을 수 있음
				virus_pos.push_back(make_pair(i, j));
			}
			if (board[i][j] == 0) {
				space_count++;
			}
		}
	}
}

void InitVisited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}

void Init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			group_number[i][j] = -1;
		}
	}
}

void SetGroupBfs(int y, int x) {
	if (group_number[y][x] != -1 || board[y][x] == WALL)
		return;

	queue<pair<int, int> > q;
	q.push(make_pair(y, x));

	int my_grp = group_count;
	group_count++;

	group_number[y][x] = my_grp;

	while(!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (OutOfRange(ny, nx)) continue;
			if (group_number[ny][nx] != -1) continue;
			if (board[ny][nx] == WALL) continue;
			
			group_number[ny][nx] = my_grp;
			q.push(make_pair(ny, nx));
		}
	}
}

void SetGroup() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			SetGroupBfs(i, j);
		}
	}
}


void CalcSpreadTime() {
	InitVisited(); // 방문 초기화
	vector<bool> visited_grp(group_count, false);


	queue<Data> q;
	int cnt = 0;

	// 시작 지점 세팅
	for (int i = 0; i < virus_pos.size(); i++) {
		if (selected[i])
		{
			int y = virus_pos[i].first;
			int x = virus_pos[i].second;
			int grp_num = group_number[y][x];

			visited_grp[grp_num] = true;
			visited[y][x] = true;
			q.push(Data(y, x, cnt));
		}
	}

	// 전체 방문 여부 검사
	for (int i = 0; i < group_count; i++) {
		if (visited_grp[i] == false)
			return;
	}


	int spread_count = 0; // 빈칸에 흩뿌려진 개수
	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		cnt = q.front().cnt;
		q.pop();

		//cout << y << ", " << x << ", cnt = " << cnt << endl;

		if (cnt > ans) {
			return;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (OutOfRange(ny, nx)) continue;
			if (board[ny][nx] == WALL) continue;
			if (visited[ny][nx]) continue;
			if (spread_count == space_count) continue; // 빈 공간 다 채움
			if (board[ny][nx] == 0) { // 빈 칸일 경우
				spread_count++;
			}

			visited[ny][nx] = true;
			q.push(Data(ny, nx, cnt + 1));
		}
	}

	ans = min(ans, cnt);
}

void Dfs(int pos, int count) {
	if (count == M) {
		// 계산
		CalcSpreadTime();
		return;
	}

	if (virus_pos.size() - pos  < M - count)
		return;

	for (int i = pos; i < virus_pos.size(); i++) {
		selected[i] = true;
		Dfs(i + 1, count + 1);
		selected[i] = false;
	}
}

void Solution() {
	Init();
	SetGroup();

	Dfs(0, 0);
}

int main() {

	FastIO();
	Input();
	Solution();

	if (ans == INF)
		ans = -1;
	cout << ans << endl;
	return 0;
}
