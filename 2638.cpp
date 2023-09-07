#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
const int MAX_SIZE = 102;

int N, M;
bool isIce[MAX_SIZE][MAX_SIZE];
int nearAirCount[MAX_SIZE][MAX_SIZE]; // 인근 공기 개수
int airParent[MAX_SIZE][MAX_SIZE]; // 공기 그룹
int airCount;

bool OutOfRange(int y, int x) {
	if (y < 0 || y >= N) return true;
	if (x < 0 || x >= M) return true;
	return false;
}

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Init() {
	airCount = 0;
	memset(nearAirCount, 0, sizeof(nearAirCount));
}

int Find(int y, int x) {
	int group = M * y + x;
	if (airParent[y][x] == group)
		return group;
	return airParent[y][x] = Find(airParent[y][x] / M, airParent[y][x] % M);
}

void Union(int y1, int x1, int y2, int x2) {
	int group1 = Find(y1, x1);
	int group2 = Find(y2, x2);

	if (group1 == group2)
		return;

	// 그룹 번호 더 작은 방향으로 합치기
	if (group1 < group2)
		airParent[group2 / M][group2 % M] = group1;
	else 
		airParent[group1 / M][group1 % M] = group2;
}


void Input() {
	cin >> N >> M;

	// 입력
	int group = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> isIce[i][j];
			airParent[i][j] = group++;
			// 아이스
			if (isIce[i][j]) {
				if (i > 0 && !isIce[i - 1][j]) nearAirCount[i][j]++; // 위 공기
				if (j > 0 && !isIce[i][j - 1]) nearAirCount[i][j]++; // 왼 공기

			}
			// 공기
			else if (!isIce[i][j]) {
				airCount++;
				if (i > 0 && !isIce[i - 1][j]) Union(i, j, i - 1, j); // 위 공기
				if (j > 0 && !isIce[i][j - 1]) Union(i, j, i, j - 1); // 왼 공기
				if (i > 0 && isIce[i - 1][j]) nearAirCount[i - 1][j]++; // 위 얼음
				if (j > 0 && isIce[i][j - 1]) nearAirCount[i][j - 1]++; // 왼 얼음
			}
		}
	}
}

// 인근의 공기 개수 2 이상 && 인근 air group이 0일 경우 삭제
bool isRemovable(int y, int x) {
	if (!isIce[y][x] || nearAirCount[y][x] < 2)
		return false;

	int groupZeroCnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (OutOfRange(ny, nx)) continue;
		if (Find(ny, nx) == 0) {
			groupZeroCnt++;
		}
	}

	if (groupZeroCnt >= 2)
		return true;
	return false;
}

int Solution() {
	int time = 0;
	vector<pair<int, int> > removedList;
	while (airCount < N * M) {
		removedList.clear();

		// 삭제할 얼음 찾기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (isRemovable(i, j)) { // 얼음 제거 가능
					removedList.emplace_back(i, j);
				}
			}
		}

		// 삭제 진행
		for (pair<int, int>& removed : removedList) {
			int y = removed.first;
			int x = removed.second;
			airCount++;

			isIce[y][x] = false;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (OutOfRange(ny, nx)) continue;
				nearAirCount[ny][nx]++;
				// 공기 그룹 합치기
				if (!isIce[ny][nx]) {
					Union(y, x, ny, nx);
				}
			}
		}

		time++;
	}

	return time;
}


int main() {
	FastIO();
	Input();
	int ans = Solution();
	cout << ans;

	return 0;
}
