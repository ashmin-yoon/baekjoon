#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 50;
const int INF = 987654321;

bool is_shark[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];

int N, M;
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool OutOfRange(int y, int x) {
	if (y < 0 || y >= N) return true;
	if (x < 0 || x >= M) return true;
	return false;
}

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> is_shark[i][j];
		}
	}
}

void BfsWriteDistance(int y, int x) {
	if (!is_shark[y][x])
		return;

	// 상어 기준 거리를 작성
	queue<pair<int, int> > q;
	queue<int> cnt_q;
	q.push(make_pair(y, x));
	cnt_q.push(0);

	int cnt = 0;
	dist[y][x] = 0; // 상어 자기 자신

	while(!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		cnt = cnt_q.front();
		q.pop();
		cnt_q.pop();


		// 이동
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int ncnt = cnt + 1;

			if (OutOfRange(ny, nx)) continue;
			// 안전 거리가 더 짧다면
			// 더 진행할 필요 없음
			if (dist[ny][nx] <= ncnt) continue; 

			// 안전 거리 갱신
			dist[ny][nx] = ncnt;
			q.push(make_pair(ny, nx));
			cnt_q.push(ncnt);
		}
	}

}

void InitDist() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dist[i][j] = INF;
		}
	}
}

void PrintDist() {
	cout << "PrintDist() ===========" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

int Solution() {
	int max_dist = 0;
	InitDist(); // 거리 초기화

	// 전체 상어 안전 거리 작성
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			BfsWriteDistance(i, j);
		}
	}

	// PrintDist();

	// 최대 안전 거리 찾기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			max_dist = max(max_dist, dist[i][j]);
		}
	}

	return max_dist;
}


int main() {

	FastIO();
	Input();
	cout << Solution();

	return 0;
}
