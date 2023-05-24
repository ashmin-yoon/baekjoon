#include <iostream>
using namespace std;
const int MAX_SIZE = 4;
const int SHARK = 0;
const int EMPTY = -1;

// 오류 찾는데 상당히 도움이 되었음
// https://www.acmicpc.net/board/view/101904

// 구현이 쉬우면서도 실수한 곳 있으면 찾기가 어려움..

typedef struct {
	int y;
	int x;
	int dir;
}Info;

int board[MAX_SIZE][MAX_SIZE];


Info info[17]; // 0은 상어


int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

bool OutOfRange(int y, int x) {
	if (y < 0 || y >= MAX_SIZE) return true;
	if (x < 0 || x >= MAX_SIZE) return true;
	return false;
}

void Input() {
	int num;
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			cin >> num;
			board[i][j] = num;

			info[num].y = i;
			info[num].x = j;
			cin >> info[num].dir;
		}
	}

}

int GetDir(int originDir, int i) {
	originDir--;
	originDir = (originDir + i) % 8;
	originDir++;
	return originDir;
}

// 물고기 위치 변경
void ChangeFishPosition(int idx, int ny, int nx) {
	// idx 의 위치
	int oldY = info[idx].y;
	int oldX = info[idx].x;
	info[idx].y = ny;
	info[idx].x = nx;

	// 새로운 위치의 기존 번호
	int num = board[ny][nx];
	board[ny][nx] = idx;
	board[oldY][oldX] = num;

	// -1
	if (num == EMPTY)
		return;

	info[num].y = oldY;
	info[num].x = oldX;
}

void MoveFish(int idx) {
	//printf("MoveFish %d\n", idx);

	int y = info[idx].y;
	int x = info[idx].x;
	int& dir = info[idx].dir; // dir은 변경 가능

	// 사라진 물고기
	if (dir == EMPTY || board[y][x] == EMPTY)
		return;

	int originDir = dir;

	// 없으면 원래 방향으로 돌아와야함
	for (int i = 0; i < 9; i++) {
		dir = GetDir(originDir, i);
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		// 이동 불가
		if (OutOfRange(ny, nx)) continue;
		if (board[ny][nx] == SHARK) continue;

		// 이동
		ChangeFishPosition(idx, ny, nx);
		break;
	}
}

// 저장
void Save(int tmp_board[MAX_SIZE][MAX_SIZE], Info tmp_info[17]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			tmp_board[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < 17; i++) {
		tmp_info[i] = info[i];
	}
}


// 불러오기
void Load(int tmp_board[MAX_SIZE][MAX_SIZE], Info tmp_info[17]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			board[i][j] = tmp_board[i][j];
		}
	}

	for (int i = 0; i < 17; i++) {
		info[i] = tmp_info[i];
	}
}

void PrintBoard(int tmp_board[MAX_SIZE][MAX_SIZE], Info tmp_info[17]) {
	cout << "PrintBoard\n";
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
//
//	for (int i = 0; i < 17; i++) {
//		info[i] = tmp_info[i];
//	}

	cout << "\n";
}

int Solution(int y, int x, int cnt) {
	//printf("Solution(%d, %d, depth = %d, (y,z) size = %d)\n", y, x, cnt, board[y][x]);

	int eat = board[y][x];
	board[y][x] = SHARK;
	info[SHARK].dir = info[eat].dir;
	info[SHARK].y = y;
	info[SHARK].x = x;

	// 잡힌 물고기 정보 삭제
	info[eat].dir = EMPTY;
	info[eat].y = EMPTY;
	info[eat].x = EMPTY;


	// 물고기 움직임
	for (int i = 1; i <= 16; i++) {
		MoveFish(i);
	}


	// 임시 데이터
	int tmp_board[MAX_SIZE][MAX_SIZE];
	Info tmp_info[17]; // 0은 상어

	// 데이터 저장
	Save(tmp_board, tmp_info);


	int ret = eat;
	// 상어 이동
	for (int i = 1; i <= 3; i++) {
		int ny = y + (i * dy[info[0].dir]);
		int nx = x + (i * dx[info[0].dir]);
		//printf("ny = %d, nx = %d\n", ny, nx);

		if (OutOfRange(ny, nx)) {
			break;
		}
		if (board[ny][nx] == EMPTY) continue;

		board[y][x] = EMPTY;
		ret = max(ret, eat + Solution(ny, nx, cnt + 1));
		// 데이터 복원
		Load(tmp_board, tmp_info);
	}

	return ret;
}

int main() {
	Input();
	cout << Solution(0, 0, 0) << endl;

	return 0;
}
