#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 50;
const int INF = 987654321;

int N, M;
const int SPACE = 0;
const int WALL = 1;
const int AVAILABLE_VIRUS = 2; 

bool selected[11];

int group_cnt = 0; // 그룹의 개수
int group_number[MAX_SIZE][MAX_SIZE]; // 각 칸의 그룹 번호
bool visited_grp[MAX_SIZE * MAX_SIZE];

vector<pair<int, int> > virus_pos; // 가능한 위치 개수 범위 [M, 10]


int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int board[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int ans = INF;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}


void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == AVAILABLE_VIRUS) {
				virus_pos.push_back(make_pair(i, j)); // 바이러스 가능 위치
			}
		}
	}
}

bool OutOfRange(int y, int x) {
	if (y < 0 || y >= N) return true;
	if (x < 0 || x >= N) return true;
	return false;
}

void InitVisited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}

void Init() {
	// 방문 초기화
	InitVisited();

	// 그룹 초기화
	group_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			group_number[i][j] = -1;
		}
	}

	for (int i = 0; i < 11; i++) {
		selected[i] = false;
	}

	ans = INF;
}

void SetGroup(int y, int x) {
	if (group_number[y][x] != -1)
		return;
	if (board[y][x] == WALL)
		return;

	queue<pair<int, int> > q;
	q.push(make_pair(y, x));

	// 그룹 지정
	int my_group = group_cnt;
	group_number[y][x] = my_group;
	group_cnt++;

	while(!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();


		// 이동
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (OutOfRange(ny, nx)) continue; // 범위
			if (board[ny][nx] == WALL) continue; // 벽
			if (group_number[ny][nx] != -1) continue; // 그룹 있음

			group_number[ny][nx] = my_group;
			q.push(make_pair(ny, nx));
		}
	}
}

void InitVistedGroup() {
	for (int i = 0; i < N * N; i++) {
		visited_grp[i] = false;
	}
}


void CalcSpreadTime() {
	queue<pair<int, int> > q;
	queue<int> time_q;

	// 시작 위치 + 방문 그룹 확인
	InitVistedGroup();
	InitVisited();
	int visited_grp_cnt = 0;
	int t = 0;
	for (int i = 0; i < virus_pos.size(); i++) {
		if (selected[i] == false) 
			continue;

		// 선택된 virus 위치만
		int y = virus_pos[i].first;
		int x = virus_pos[i].second;
		int grp_num = group_number[y][x];

		if (visited_grp[grp_num] == false)
		{
			visited_grp_cnt++;
			visited_grp[grp_num] = true;
		}

		// 시작 지점 추가
		visited[y][x] = true;
		q.push(virus_pos[i]);
		time_q.push(t);
	}

	// 총 그룹 개수, 방문한 그룹 개수 비교
	// 맵 전체 못 덮음
	if (visited_grp_cnt != group_cnt) {
		return;
	}


	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		t = time_q.front();
		q.pop(); 
		time_q.pop();

		//cout << y << ", " << x << ", " << t << endl;

		// 중단 조건
		// 이전에 구한 확산 시간 비교
		if (t > ans)
			return;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (OutOfRange(ny, nx)) continue;
			if (board[ny][nx] == WALL) continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = true;
			time_q.push(t+ 1);
			q.push(make_pair(ny, nx));
		}
	}

	// cout << "시간 = " << t << endl;
	ans = min(ans, t);
}

void Dfs(int pos, int count) {
	if (count == M) {
		CalcSpreadTime();
		return;
	}

	// 남은 개수가 < M - count 보다 작으면 깊어지지 않음
	if (virus_pos.size() - pos < M - count)
		return;

	for (int i = pos; i < virus_pos.size(); i++) {
		selected[i] = true;
		Dfs(i + 1, count + 1);
		selected[i] = false;
	}
}

void PrintGroupNum() {
	cout << "PrintGroupNum ============\n";
	cout << group_cnt << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << group_number[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Solution() {
	Init();

	// 그룹 설정
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			SetGroup(i, j);
		}
	}

	// PrintGroupNum();

	// BruteForce
	Dfs(0, 0);
}

int main() {
	FastIO();
	Input();
	Solution();

	// 정답
	if (ans == INF)
		ans = -1;
	cout << ans;

}
