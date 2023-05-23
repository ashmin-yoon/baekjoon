#include <iostream>
using namespace std;
const int MAX_SIZE = 10000;
const int GREEN = 0;
const int BLUE = 1;

int N;
bool green[7][4]; // 0, 1 행 특별 // 한 행 더
bool blue[4][7]; // 0, 1 열 특별
int score = 0;

// t = 1  (y, x)에 1 x 1 ㅁ
// t = 2  (y, x)에 1 x 2 ㅁㅁ
// t = 3  (y, x)에 2 x 1
// ㅁ
// ㅁ

typedef struct CMD {
	int t;
	int y;
	int x;
}CMD;
CMD cmd[MAX_SIZE];

void Init() {

	// 편의상 추가로 한 줄 늘리고 1로 채움
	for (int i = 0; i < 4; i++) {
		green[6][i] = true;
		blue[i][6] = true;
	}
}

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cmd[i].t;
		cin >> cmd[i].y;
		cin >> cmd[i].x;
	}
}



bool IsFullLine(int color, int line) {
	bool isFull = true;

	if (color == GREEN) {
		for (int j = 0; j < 4; j++) {
			if (green[line][j] == false)
				return false;
		}
	}

	else if (color == BLUE) {
		for (int i = 0; i < 4; i++) {
			if (blue[i][line] == false)
				return false;
		}
	}

	return isFull;
}

void DeleteLine(int color, int line) {

	if (color == GREEN) {
		// 라인 당기기
		for (int l = line; l > 0; l--) {
			for (int j = 0; j < 4; j++) {
				green[l][j] = green[l - 1][j];
			}
		}

		// 라인 삭제
		for (int j = 0; j < 4; j++) {
			green[0][j] = false;
		}
	}

	else if (color == BLUE) {
		// 라인 당기기
		for (int l = line; l > 0; l--) {
			for (int i = 0; i < 4; i++) {
				blue[i][l] = blue[i][l - 1];
			}
		}

		for (int i = 0; i < 4; i++) {
			blue[i][0] = false;
		}

	}
}


void SpecialLine() {
	int line_cnt = 0;
		// 특별라인

	// GREEN
	line_cnt = 0;
	for (int l = 0; l < 2; l++) {
		for (int j = 0; j < 4; j++) {
			if (green[l][j]) {
				line_cnt++;
				break;
			}
		}
	}

	// 특별 라인 수 만큼 삭제
	for (int cnt = 0; cnt < line_cnt; cnt++) {
		DeleteLine(GREEN, 5);
	}

	// BLUE
	line_cnt = 0;
	for (int l = 0; l < 2; l++) {
		for (int i = 0; i < 4; i++) {
			if (blue[i][l]) {
				line_cnt++;
				break;
			}
		}
	}

	// 특별 라인 수 만큼 삭제
	for (int cnt = 0; cnt < line_cnt; cnt++) {
		DeleteLine(BLUE, 5);
	}
}



// ㅁ
void MoveT1(int y, int x) {

	// green
	for (int i = 0; i < 6; i++) {
		if (green[i + 1][x]) {
			green[i][x] = true;
			// 라인 검사
			if (IsFullLine(GREEN, i)) {
				DeleteLine(GREEN, i);
				score++;
			}
			break;
		}
	}

	// blue
	for (int j = 0; j < 6; j++) {
		if (blue[y][j + 1]) {
			blue[y][j] = true;
			// 라인 검사
			if (IsFullLine(BLUE, j)) {
				DeleteLine(BLUE, j);
				score++;
			}
			break;
		}
	}
}

// ㅁㅁ
void MoveT2(int y, int x) {

	// green
	for (int i = 0; i < 6; i++) {
		if (green[i + 1][x] || green[i + 1][x + 1]) {
			green[i][x] = true;
			green[i][x + 1] = true;

			// 라인 검사
			if (IsFullLine(GREEN, i)) {
				DeleteLine(GREEN, i);
				score++;
			}
			break;
		}
	}

	// blue
	for (int j = 0; j < 5; j++) {
		if (blue[y][j + 2]) {
			blue[y][j] = true;
			blue[y][j + 1] = true;
			// 라인 검사
			if (IsFullLine(BLUE, j)) {
				DeleteLine(BLUE, j);
				score++;
			}
			if (IsFullLine(BLUE, j + 1)) {
				DeleteLine(BLUE, j + 1);
				score++;
			}
			break;
		}
	}

}

// ㅁ
// ㅁ
void MoveT3(int y, int x) {
	// green
	for (int i = 0; i < 5; i++) {
		if (green[i + 2][x]) {
			green[i][x] = true;
			green[i + 1][x] = true;

			// 라인 검사
			if (IsFullLine(GREEN, i)) {
				DeleteLine(GREEN, i);
				score++;
			}

			if (IsFullLine(GREEN, i + 1)) {
				DeleteLine(GREEN, i + 1);
				score++;
			}
			break;
		}
	}

	// blue
	for (int j = 0; j < 6; j++) {
		if (blue[y][j + 1] || blue[y + 1][j + 1]) {
			blue[y][j] = true;
			blue[y + 1][j] = true;
			// 라인 검사
			if (IsFullLine(BLUE, j)) {
				DeleteLine(BLUE, j);
				score++;
			}
			break;
		}
	}

}


void ExecuteCMD(int cmd_idx) {
	int t = cmd[cmd_idx].t;
	int y = cmd[cmd_idx].y;
	int x = cmd[cmd_idx].x;

	switch(t) {
		case 1: MoveT1(y, x);
			break;
		case 2: MoveT2(y, x);
			break;
		case 3: MoveT3(y, x);
			break;
	}
	SpecialLine();
}



// 칸의 개수
int GetNumberOfBlockSpace() {
	int cnt = 0;
	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (green[i][j])
				cnt++;
			if (blue[j][i])
				cnt++;
		}
	}
	return cnt;
}

void PrintGreen() {
	cout << "PrintGreen\n";

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			cout << green[i][j] << " ";
		}
		cout << "\n";
	}
}

void PrintBlue() {
	cout << "PrintBlue\n";

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			cout << blue[i][j] << " ";
		}
		cout << "\n";
	}
}


void Solution() {
	for (int i = 0; i < N; i++) {
		ExecuteCMD(i);
		//PrintGreen();
		//PrintBlue();
		//cout << "score = " << score << endl;
		//cout << "\n";
	}
}

int main() {
	FastIO();
	Init();
	Input();
	Solution();

	cout << score << "\n";
	cout << GetNumberOfBlockSpace() << "\n";

	return 0;
}
