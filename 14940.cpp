#include <iostream>
#include <queue>
using namespace std;
const int MAX_SIZE = 1000;

const int RESTRICTION = 0;
const int AVAILABLE = 1;
const int DESTINATION = 2;

int N, M;
int land[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int y, x;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> land[i][j];
			// 시작 지점(목적지)
			if (land[i][j] == DESTINATION) {
				y = i;
				x = j;
			}
			else if (land[i][j] == RESTRICTION) {
				dist[i][j] = RESTRICTION; // 거리 0 표시
			}
		}
	}
}

// 초기화
void InitDist() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			dist[i][j] = -1;
		}
	}
}

bool OutOfRange(int y, int x) {
	if (y < 0 || y >= MAX_SIZE) return true;
	if (x < 0 || x >= MAX_SIZE) return true;
	return false;
}

// 문제 해결
void Bfs() {
	queue<pair<int, int> > q;

	q.push(make_pair(y, x));
	visited[y][x] = true;
	dist[y][x] = 0;

	while(!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		// 인근 4칸 
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (OutOfRange(ny, nx)) continue;
			if (visited[ny][nx]) continue;
			if (land[ny][nx] == RESTRICTION) continue;

			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
			dist[ny][nx] = dist[y][x] + 1;
		}
	}
}

// 거리 출력
void PrintDist() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	FastIO();
	InitDist();
	Input();
	Bfs();
	PrintDist();

	return 0;
}
