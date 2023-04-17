#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 20;
const int INF = 987654321;

int board[MAX_SIZE][MAX_SIZE];
char tmp[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
bool is_furniture[MAX_SIZE][MAX_SIZE];

int W, H;
int dirty_cnt = 0;

int robot_y, robot_x;

int dist[11][11]; // 거리 0 = robot, 1 ~ 10  dirty
bool selected[11];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

/**
	10%에서 자꾸 틀렸다.

	개별적으로 진행하면 답이 잘 나왔으나
	연속해서 진행하면 틀린 답을 출력했다.

	원인은 변수 초기화
	실수라고 표현할 수 있지만
	이런 부분을 놓친 것도 곧 실력이라 판단된다.
	*/


bool OutOfRange(int y, int x) {
	if (y < 0 || y >= H) return true;
	if (x < 0 || x >= W) return true;
	return false;
}

// 좌표
typedef struct Point {
	int y;
	int x;
	Point() {}
	Point(int y, int x) :
		y(y), x(x) {}
}Point;

Point point[11];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

bool Input() {
	cin >> W >> H;

	if (W == 0 && H == 0)
		return false;

	int idx = 1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> tmp[i][j];

		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			board[i][j] = 0; // 기본
			switch(tmp[i][j]) 
			{
				case '*': // 더럽
					point[idx].y = i; // 더러운 위치 저장
					point[idx].x = j;
					board[i][j] = idx; // dirty 값 변경
					idx++;
					break;
				case 'x': // 가구
					is_furniture[i][j] = true;
					break;
				case 'o': // 로봇
					point[0].y = i;
					point[0].x = j;
					break;
				case '.': // 깨끗
					break;
			}
		}
	}

	dirty_cnt = idx - 1; // 더러운 개수
	return true;
}

void InitVisited() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			visited[i][j] = false;
		}
	}
}

void InitDist() {
for (int i = 0; i < 11; i++) {
		selected[i] = false;
		for (int j = 0; j < 11; j++) {
			dist[i][j] = INF;
		}
		dist[i][i] = 0; // 자기 자신
	}

}

void InitSelected() {
	for (int i = 0; i < 11; i++) {
		selected[i] = false;
	}
}

void InitFurniture() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			is_furniture[i][j] = false;
		}
	}
}

void Init() {
	// dist, selected
	InitSelected();
	InitVisited();
	InitDist();
	InitFurniture();
}



void PrintMap() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << board[i][j] << "\t";
		}
		cout << "\n";
	}
}


// Point[idx] 로부터 거리 구하기
void CalcDist(int idx) {
	InitVisited();

	queue<Point> q;
	queue<int> cnt_q;
	q.push(point[idx]);
	cnt_q.push(0);

	visited[(point[idx].y)][(point[idx].x)] = true;

	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = cnt_q.front();
		q.pop(); cnt_q.pop();

		// board의 0 = clear
		// board의 1 ~ 10 = dirty idx 번호
		// 더러운 구역(1~10) - Input 에서 값을 변경했음
		if (0 < board[y][x] && board[y][x] <= 10)
		{
			int dirty_idx = board[y][x];
			dist[idx][dirty_idx] = cnt;
		}

		// 이동
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (OutOfRange(ny, nx)) continue; // 범위
			if (visited[ny][nx]) continue; // 방문
			if (is_furniture[ny][nx]) continue; // 가구

			visited[ny][nx] = true;
			q.push(Point(ny, nx));
			cnt_q.push(cnt + 1);
		}
	}

}


// 거리를 BruteForce로 구함
int Dfs(int index, int count, int sum) {
	int rev = INF;

	// 종료 조건 -> 전체 더러운 곳 방문
	if (count == dirty_cnt) {
		return sum;	
	}

	// dirty 전체 순회
	for (int next = 1; next <= dirty_cnt; next++) {
		if (selected[next]) continue; // 선택됨
		int dist_sum = sum + dist[index][next]; 

		selected[next] = true; // 선택
		rev = min(rev, Dfs(next, count + 1, dist_sum));
		selected[next] = false; // 선택 해제
	}

	return rev;
}

void PrintDist() {
	cout << "PrintDist ===============\n";
	for (int i = 0; i <= dirty_cnt; i++) {
		cout << i << " ";
		for (int j = 0; j <= dirty_cnt; j++) {
			cout << dist[i][j] << " ";	
		}
		cout << endl;
	}
}

int Solution() {
	// 각 칸(로봇, 더러운 곳)에서의 거리 계산
	for (int i = 0; i <= dirty_cnt; i++) {
		CalcDist(i);
	}


	// 방문할 수 없는 칸 존재 확인
	// 주의 <= dirty cnt 포함
	for (int i = 1; i <= dirty_cnt; i++) { 
		if (dist[0][i] == INF)
			return -1;
	}

	// 구한 거리를 이용해서 브루트 포스 진행
	return Dfs(0, 0, 0);
}

int main() {

	FastIO();

	while(true) {
		Init();

		if (Input() == false)
			break;
		cout << Solution() << "\n";
	}

	return 0;
}
