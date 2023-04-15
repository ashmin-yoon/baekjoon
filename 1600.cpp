#include <iostream>
#include <queue>
using namespace std;
const int MAX_SIZE = 200;

int K;
int H, W;

bool is_obstacle[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][31];

// 말 이동
int night_dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int night_dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

// 일반 이동
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool OutOfRange(int y, int x) {
	if (y < 0 || y >= H) return true;
	if (x < 0 || x >= W) return true;
	return false;
}

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> K;
	cin >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> is_obstacle[i][j];
		}
	}
}

typedef struct Point {
	int y;
	int x;
	int cnt;
	int k;
	Point(int y, int x, int cnt, int k) :
		y(y), x(x), cnt(cnt), k(k) { }
}Point;

int Bfs() {


	queue<Point> q;
	q.push(Point(0, 0, 0, 0));

	while(!q.empty()) 
	{
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		int k = q.front().k;
		q.pop();

	//	cout << "y = " << y << ", x = " << x << ", cnt = " << cnt << ", k = " << k << endl;

		if (y == H - 1 && x == W - 1) {
			return cnt;
		}



		// 일반
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (OutOfRange(ny, nx)) continue;
			if (visited[ny][nx][k]) continue;
			if (is_obstacle[ny][nx]) continue; // 막혀있음

			visited[ny][nx][k] = true;
			q.push(Point(ny, nx, cnt + 1, k));
		}


		// 회수 제한
		if (k >= K)
			continue;

		// 말 이동
		for (int i = 0; i < 8; i++) {
			int ny = y + night_dy[i];
			int nx = x + night_dx[i];

			if (OutOfRange(ny, nx)) continue;
			if (is_obstacle[ny][nx]) continue; // 막혀있음
			if (visited[ny][nx][k + 1]) continue;

			visited[ny][nx][k+1] = true;
			q.push(Point(ny, nx, cnt + 1, k + 1));
		}
	}

	return -1;
}

int main() {

	FastIO();
	Input();
	cout << Bfs();


	return 0;
}
