#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 102;
const char WALL = '*';
const char SPACE = '.';
const char DOOR = '#';
const int INF = 987654321;

// 1. 약간의 힌트 찾아봄
// 2. 시간 초과로 인해 좀 더 자세히 찾아봄
// 3. 해결 방법은 익혔으나 연습 필요

int H, W;
bool visited[MAX_SIZE][MAX_SIZE][3]; // 각 방문 기록 // 0, 1 죄수, 2 외부인 
int dist[MAX_SIZE][MAX_SIZE][3];		// 각 죄수별 해당 위치까지의 문 개수
char board[MAX_SIZE][MAX_SIZE];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

typedef struct Point {
	int y;
	int x;
	Point() {}
	Point(int y, int x) :
		y(y), x(x) {}
}Point;

typedef struct Info {
	int y;
	int x;
	int break_cnt;
	Info() {}
	Info(int y, int x, int break_cnt) :
		y(y), x(x), break_cnt(break_cnt) {}
}Info;


// break_cnt 기준 오름 차순 정렬
struct cmp {
	bool operator() (Info& p1, Info& p2) {
		return p1.break_cnt > p2.break_cnt;
	}
};



Point p[2]; // 죄수


void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			visited[i][j][0] = visited[i][j][1] = visited[i][j][2] = false;
			dist[i][j][0] = dist[i][j][1] = dist[i][j][2] = INF;
			board[i][j] = '.';
		}
	}
}

void Input() {
	int idx = 0;
	cin >> H >> W;
	H += 2;
	W += 2; // 조금 더 크게 테두리 생성
	for (int i = 1; i < H - 1; i++) {
		for (int j = 1; j < W - 1; j++) {
			cin >> board[i][j];
			if (board[i][j] == '$')
			{
				p[idx] = Point(i, j);
				idx++;
			}
		}
	}
}


void PrintMap() {
	cout << "=================\n";
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
}


void PrintInfo(int idx) {
	cout << "PrintInfo " << idx << "=================\n";
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (dist[i][j][idx] == INF)
				cout << 0;
			else 
				cout << dist[i][j][idx];
		}
		cout << endl;
	}
	cout << endl << endl;
}



bool OutOfRange(int y, int x) {
	if (y < 0 || y >= H) return true;
	if (x < 0 || x >= W) return true;
	return false;
}

bool OutOfRange(Info p) {
	if (p.y < 0 || p.y >= H) return true;
	if (p.x < 0 || p.x >= W) return true;
	return false;
}


// 거리 계산
void Dijkstra(int y, int x, int idx) {

	priority_queue<Info, vector<Info>, cmp> q;
	q.push(Info(y, x, 0));

	// [y][x][idx]
	visited[y][x][idx] = true;

	while(!q.empty())
	{
		int y = q.top().y;
		int x = q.top().x;
		int cnt = q.top().break_cnt;
		q.pop();

		dist[y][x][idx] = cnt;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (OutOfRange(ny, nx)) continue;
			if (board[ny][nx] == WALL) continue;
			if (visited[ny][nx][idx]) continue;

			int ncnt = cnt;
			if (board[ny][nx] == DOOR)
				ncnt++;

			visited[ny][nx][idx] = true;
			q.push(Info(ny, nx, ncnt));
		}
	}
}

int FindCommonShortDist() {
	int short_dist = INF;

	// 특정 점으로 모여서 함께 탈출
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (board[i][j] == WALL) continue;
			if (dist[i][j][0] == INF || dist[i][j][1] == INF 
					|| dist[i][j][2] == INF) continue; // 하나라도 경로가 없다면 무시
			// 계산
			int distance = dist[i][j][0] + dist[i][j][1] + dist[i][j][2];
			if (board[i][j] == DOOR)
			{
				distance -= 2; // 공통으로 잡히기 때문에 차감
			}
			short_dist = min(short_dist, distance);
		}
	}
	return short_dist;
}

int Solution() {
	int rev = INF;

	// 죄수 ~ 각 위치별 거리(문 개수) 계산
	Dijkstra(p[0].y, p[0].x, 0);	
	Dijkstra(p[1].y, p[1].x, 1);	
	Dijkstra(0, 0, 2);	 // 전체 주변 테투리 두르고 각 칸 별 최소 문 개수

//	PrintInfo(0);
//	PrintInfo(1);
//	PrintInfo(2);

	// 각자 개인 탈출
	int p1_solo = dist[0][0][0]; // 0, 0 은 빈 공간 
	int p2_solo = dist[0][0][1];

	// 특정 위치로 만나서 같이 빠져나감
	int short_common_dist = FindCommonShortDist();

	rev = min(p1_solo + p2_solo, short_common_dist);
	return rev;
	
}

int main() {
	FastIO();
	int T;
	cin >> T;

	while(T--)
	{
		Init();
		Input();
		cout << Solution() << endl;
//		PrintInfo(0);
//		PrintInfo(1);
//		PrintMap();
	}

}

