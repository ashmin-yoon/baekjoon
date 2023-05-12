#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
const int MAX_SIZE = 50;

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

int N;
int L, R; // L <= 인구수 차이 <= R

int country[MAX_SIZE][MAX_SIZE];
bool isOpen[MAX_SIZE][MAX_SIZE][4]; // 4 방향
bool visited[MAX_SIZE][MAX_SIZE];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool GetBorderOpenStatus(int population_diff) {
	if (L <= population_diff && population_diff <= R)
		return true;
	return false;
}

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
	cin >> N;
	cin >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> country[i][j];
		}
	}
}

void InitBorderStatusAndVisited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
			for (int k = 0; k < 4; k++) {
				isOpen[i][j][k] = false;
			}
		}
	}
}


bool OpenBorder() {
	bool ret = false;

	// 우측과 아래칸만 검사하면 전체
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int curr = country[i][j];

			// 우측
			if (!OutOfRange(i, j + 1)) {
				int right_diff = abs(curr - country[i][j + 1]);
				if (GetBorderOpenStatus(right_diff)) {
					isOpen[i][j][RIGHT] = true;
					isOpen[i][j + 1][LEFT] = true;
					ret = true;
				}
			}


			// 아래측
			if (!OutOfRange(i + 1, j)) {
				int down_diff = abs(curr - country[i + 1][j]);
				if (GetBorderOpenStatus(down_diff)) {
					isOpen[i][j][DOWN] = true;
					isOpen[i + 1][j][UP] = true;
					ret = true;
				}
			}
		}
	}

	return ret;
}


// BFS 열린 국경으로 인구 조정
void MovePopulation(int y, int x) {
	if (visited[y][x])
		return;


	queue<pair<int, int> > q;
	queue<pair<int, int> > path;
	int sum = 0;
	int country_cnt = 0;

	// 시작 지점
	visited[y][x] = true;
	q.push(make_pair(y, x));

	// 찾기 시작
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		path.push(q.front());
		q.pop();

		sum += country[y][x];
		country_cnt++;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (OutOfRange(ny, nx)) continue;
			if (visited[ny][nx]) continue;
			if (!isOpen[y][x][i]) continue; // 주의 현재 위치 기준 + 방향으로 검사

			visited[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}
	}

	int population = sum / country_cnt;

	// 인구 조정
	while(!path.empty()) {
		y = path.front().first;
		x = path.front().second;
		path.pop();

		country[y][x] = population;
	}

}

void PrintCountry() {
	cout << "=============================\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << country[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "\n";

}

int Solution() {

	int cnt = 0;
	while (true) {
		InitBorderStatusAndVisited(); // visited, border status
		bool status = OpenBorder();

		// 열수 없음
		if (status == false)
			break;

		// 이동
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				MovePopulation(i, j);
			}
		}
		cnt++;
		//PrintCountry();
	}
	
	return cnt;
}

int main() {
	FastIO();
	Input();
	int ans = Solution();
	cout << ans;


	return 0;
}
