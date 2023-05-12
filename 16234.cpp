#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
const int MAX_SIZE = 50;

int N;
int L, R; // L <= 인구수 차이 <= R

// 시간 단축
// MovePopulation 에서 queue 생성 -> 
// 전역 queue 공통으로 사용

queue<pair<int, int> > q;
queue<pair<int, int> > path;

int country[MAX_SIZE][MAX_SIZE];
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

void Init() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}


// BFS 열린 국경으로 인구 조정
bool MovePopulation(int y, int x) {
	if (visited[y][x])
		return false;

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

		int curr_popul = country[y][x];
		sum += curr_popul;
		country_cnt++;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (OutOfRange(ny, nx)) continue;
            if (visited[ny][nx]) continue;
			int popul_diff = abs(curr_popul - country[ny][nx]); // 이웃 나라 인구
			if (!GetBorderOpenStatus(popul_diff)) continue; // 국경을 열 수 없음

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

	// 이동이 일어났는지 여부
	if (country_cnt >= 2)
		return true;
	else
		return false;
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
		bool move_status = false;
		Init(); // visited, queue

		// 이동
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (MovePopulation(i, j))
					move_status = true;
			}
		}

		// 중단 조건 = 이동 없음
		if (move_status == false)
			break;

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
