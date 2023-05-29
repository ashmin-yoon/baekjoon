#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
const int INF = 987654321;

bool isLight[MAX_SIZE][MAX_SIZE];
bool backup[MAX_SIZE][MAX_SIZE];

int dy[4] = {-1 ,0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	char ch;
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			cin >> ch;
			isLight[i][j] = ch == 'O' ? true : false;
		}
	}
}

bool OutOfRange(int y, int x) {
	if (y < 0 || y >= MAX_SIZE) return true;
	if (x < 0 || x >= MAX_SIZE) return true;
	return false;
}

void TurnOnConditon(int y, int x) {

	isLight[y][x] = !isLight[y][x];

	// 주변
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (!OutOfRange(ny, nx)) {
			isLight[ny][nx] = !isLight[ny][nx];
		}
	}

}

void Backup() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			backup[i][j] = isLight[i][j];
		}
	}
}

void CopyBackupToIsLight() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			isLight[i][j] = backup[i][j];
		}
	}
}

int RunTC(int tc) {

	int turnOnCount = 0;

	for (int i = 1; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			if (isLight[i - 1][j]) {
				TurnOnConditon(i, j);
				turnOnCount++;
			}
		}
	}

	return turnOnCount;
}

bool IsDone() {
	for (int j = 0; j < MAX_SIZE; j++) {
		if (isLight[MAX_SIZE - 1][j])
			return false;
	}

	return true;
}

void PrintLight() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			cout << isLight[i][j] << " ";
		}
		cout << endl;
	}
}

int Solution() {
	int ans = INF;
	Backup();

	// 0행 따로 처리
	// 경우의 수 전체 탐색
	// 0 행의 경우에 따라 아래 전구들은 필연적으로 최소로 끌 수 있다.
	int T = 1 << MAX_SIZE;
	for (int tc = 0; tc < T; tc++) {
		int turnOnCount = 0;
		CopyBackupToIsLight();

		// 선택된 전구
		for (int j = 0; j < MAX_SIZE; j++) {
			if (tc & (1 << j)) {
				TurnOnConditon(0, j);
				turnOnCount++;
			}
		}

		// 테스트 케이스 진행
		turnOnCount += RunTC(tc); 

		if (IsDone() && ans > turnOnCount)
			ans = turnOnCount;
	}

	if (ans == INF)
		return -1;
	return ans;
}

int main() {
	FastIO();
	Input();
	cout << Solution();

	return 0;
}
