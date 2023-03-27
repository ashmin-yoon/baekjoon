#include <iostream>
#include <algorithm>

using namespace std;
const int MAP_SIZE = 50;

char map[MAP_SIZE][MAP_SIZE];
int n = 0;
int rCount[MAP_SIZE];
int cCount[MAP_SIZE];

int SearchRight(int y, int x) {
	int rightChangeMax = 0;

	if (x < 0 || n - 1 <= x) {
		return 0;
	}
	// 맵 복사
	char tmpMap[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmpMap[i][j] = map[i][j];
		}
	}


	// 검사
	// tmpMap 오른쪽
	if(tmpMap[y][x] != tmpMap[y][x+1]) {
		char tmp = tmpMap[y][x];
		tmpMap[y][x] = tmpMap[y][x+1];
		tmpMap[y][x+1] = tmp;
	} else {
		return 0;
	}

	for (int r = 0; r < n; r++) {
		if (r != y) {
			rightChangeMax = max(rightChangeMax, rCount[r]);
		}
	}

	for (int c = 0; c < n; c++) {
		if (c != x && c != x+1) {
			rightChangeMax = max(rightChangeMax, cCount[c]);
		}
	}

	// 바뀐 행 최대 개수 검사
	char ch = tmpMap[y][0];
	int count = 0;
	int tmpMax = 0;

	for (int j = 0; j < n; j++) {
		if (ch == tmpMap[y][j]) {
			count++;
		}
		else {
			tmpMax = max(tmpMax, count);
			ch = tmpMap[y][j];
			count = 1;
		}
	}

	tmpMax = max(tmpMax, count);
	rightChangeMax = max(rightChangeMax, tmpMax);

	// 바뀐 열 최대 개수 검사
	ch = tmpMap[0][x];
	count = 0;
	tmpMax = 0;
	for (int i = 0; i < n; i++) {
		if (ch == tmpMap[i][x]) {
			count++;
		}
		else {
			tmpMax = max(tmpMax, count);
			ch = tmpMap[i][x];
			count = 1;
		}
	}
	tmpMax = max(tmpMax, count);
	rightChangeMax = max(rightChangeMax, tmpMax);

	ch = tmpMap[0][x+1];
	count = 0;
	tmpMax = 0;
	for (int i = 0; i < n; i++) {
		if (ch == tmpMap[i][x+1]) {
			count++;
		}
		else {
			tmpMax = max(tmpMax, count);
			ch = tmpMap[i][x+1];
			count = 1;
		}
	}
	tmpMax = max(tmpMax, count);
	
	rightChangeMax = max(rightChangeMax, tmpMax);
	// cout << y << ", " << x << " =  " << rightChangeMax << endl;
	return rightChangeMax;
}

int SearchDown(int y, int x) {
	int downChangeMax = 0;

	if (y < 0 || n - 1 <= y) {
		return 0;
	}

	// 맵 복사
	char tmpMap[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmpMap[i][j] = map[i][j];
		}
	}


	// 검사

	// tmpMap 아래칸
	if(tmpMap[y][x] != tmpMap[y+1][x]) {
		char tmp = tmpMap[y][x];
		tmpMap[y][x] = tmpMap[y+1][x];
		tmpMap[y+1][x] = tmp;
	} else {
		return 0;
	}

	for (int r = 0; r < n; r++) {
		if (r != y && r != y+1) {
			downChangeMax = max(downChangeMax, rCount[r]);
		}
	}

	for (int c = 0; c < n; c++) {
		if (c != x) {
			downChangeMax = max(downChangeMax, cCount[c]);
		}
	}


	// 바뀐 행 최대 개수 검사
	char ch = tmpMap[y][0];
	int count = 0;
	int tmpMax = 0;
	for (int j = 0; j < n; j++) {
		if (ch == tmpMap[y][j]) {
			count++;
		}
		else {
			tmpMax = max(tmpMax, count);
			ch = tmpMap[y][j];
			count = 1;
		}
	}
	tmpMax = max(tmpMax, count);
	downChangeMax = max(downChangeMax, tmpMax);

	ch = tmpMap[y+1][0];
	count = 0;
	tmpMax = 0;
	for (int j = 0; j < n; j++) {
		if (ch == tmpMap[y+1][j]) {
			count++;
		}
		else {
			tmpMax = max(tmpMax, count);
			ch = tmpMap[y+1][j];
			count = 1;
		}
	}
	tmpMax = max(tmpMax, count);
	downChangeMax = max(downChangeMax, tmpMax);
	

	// 바뀐 열 최대 개수 검사
	ch = tmpMap[0][x];
	count = 0;
	tmpMax = 0;

	for (int i = 0; i < n; i++) {
		if (ch == tmpMap[i][x]) {
			count++;
		}
		else {
			tmpMax = max(tmpMax, count);
			ch = tmpMap[i][x];
			count = 1;
		}
	}

	tmpMax = max(tmpMax, count);

	downChangeMax = max(downChangeMax, tmpMax);
	//cout << y << ", " << x << " =  " << downChangeMax << endl;
	return downChangeMax;
}

int main() {
	cin >> n;

	// 맵 입력
	char ch;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ch;
			map[i][j] = ch;
		}
	}
	
	// 각 행 최대 개수 검사
	for (int i = 0; i < n; i++) {
		ch = map[i][0];
		int count = 0;
		int tmpMax = 0;

		for (int j = 0; j < n; j++) {
			if (ch == map[i][j]) {
				count++;
			}
			else {
				tmpMax = max(tmpMax, count);
				ch = map[i][j];
				count = 1;
			}
		}

		tmpMax = max(tmpMax, count);
		rCount[i] = tmpMax;
		//cout << rCount[i] << endl;
	}

	//cout << endl;
	// 각 열 최대 개수 검사	
	for (int j = 0; j < n; j++) {
		ch = map[0][j];
		int count = 0;
		int tmpMax = 0;

		for (int i= 0; i < n; i++) {
			if (ch == map[i][j]) {
				count++;
			}
			else {
				tmpMax = max(tmpMax, count);
				ch = map[i][j];
				count = 1;
			}
		}
		tmpMax = max(tmpMax, count);
		cCount[j] = tmpMax;
		//cout << cCount[j];
	}

	// 자신의 우측, 아래 칸만 검사
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, SearchRight(i, j));
			ans = max(ans, SearchDown(i, j));
		}
	}

	//cout << endl;
	cout << ans << endl;
	return 0;
}


