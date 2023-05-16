#include <iostream>
using namespace std;
const int MAX_SIZE = 101;
int R, C;
int M; // 상어 수

const int UP = 1;
const int DOWN = 2;
const int RIGHT = 3;
const int LEFT = 4;

int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, 1, -1};



typedef struct Shark {
	int speed;
	int direction;
	int size;
	Shark() {
		speed = 0;
		direction = 0;
		size = 0;
	}

	Shark(int speed, int direction, int size) :
		speed(speed), direction(direction), size(size) {}
}Shark;

Shark grid[MAX_SIZE][MAX_SIZE];
Shark tmp[MAX_SIZE][MAX_SIZE];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

bool OutOfRange(int y, int x) {
	if (y < 1 || y > R) return true;
	if (x < 1 || x > C) return true;
	return false;
}

void Input() {
	cin >> R >> C >> M;

	int r, c; // 상어 위치
	int s, d, z; // 속력, 방향, 크기
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		grid[r][c] = Shark(s, d, z);
	}
}


void InitTmp() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			tmp[i][j].direction = 0;
			tmp[i][j].size = 0;
			tmp[i][j].speed = 0;
		}
	}
}

void CopyTmpToGrid() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			grid[i][j] = tmp[i][j];
		}
	}
}

void MoveShark(int i, int j) {
	int& dir = grid[i][j].direction;
	int speed = grid[i][j].speed;
	if (dir == 0) 
		return;

	//printf("MoveShark(%d, %d)\n", i, j);

	// 속력 없음
	if (speed == 0) {
		// tmp 칸에 상어 없음 || tmp 칸 상어가 더 작음
		if (tmp[i][j].direction == 0 || tmp[i][j].size < grid[i][j].size) {
			tmp[i][j] = grid[i][j];
		}
		return;
	}


	int curr_y = i;
	int curr_x = j;


	// 방향에 따른 경우의 수 줄이기
	if (dir == LEFT || dir == RIGHT)
		speed %= (C - 1) * 2;
	if (dir == UP || dir == DOWN)
		speed %= (R - 1) * 2;


	// 이동
	for (int m = 0; m < speed; m++) {
		int ny = curr_y + dy[dir];
		int nx = curr_x + dx[dir];

		if (OutOfRange(ny, nx)) {

			// 방향 전환
			if (dir == LEFT) {
				dir = RIGHT;
				curr_x++;
			}
			else if (dir == RIGHT) {
				dir = LEFT;
				curr_x--;
			}
			else if (dir == UP) {
				dir = DOWN;
				curr_y++;
			}
			else if (dir == DOWN) {
				dir = UP;
				curr_y--;
			}
			continue;
		}

		curr_y = ny;
		curr_x = nx;
	}

	//printf("이동후 y = %d, x = %d\n", curr_y, curr_x);

	// 상어 이동 확정
	if (tmp[curr_y][curr_x].direction == 0 || tmp[curr_y][curr_x].size < grid[i][j].size) {
		tmp[curr_y][curr_x] = grid[i][j];
	}
}


void MoveAllShark() {

	InitTmp();

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			MoveShark(i, j);
		}
	}
	CopyTmpToGrid();
}

void PrintShark(int person_x) {
	printf("=====================\n");
	printf("person_x = %d\n", person_x);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (grid[i][j].direction == 0)
				printf("0 ");
			else
				printf("%d ", grid[i][j].size);
		}
		printf("\n");
	}
}

int Solution() {
	int person_x = 0;
	int fish_caught = 0;

	while(person_x < C)
	{
		//PrintShark(person_x);
		// 1. 오른쪽으로 이동
		person_x++;

		// 2. 같은 열 가장 가까운 상어 잡기
		for (int r = 1; r <= R; r++) {
			if (grid[r][person_x].direction != 0) {
				fish_caught += grid[r][person_x].size;
				grid[r][person_x].direction = 0;
				grid[r][person_x].size = 0;
				break;
			}
		}

		// 3. 상어 이동
		MoveAllShark();
	}
	//PrintShark(person_x);

	return fish_caught;
}


int main() {
	FastIO();
	Input();
	cout << Solution();

	return 0;
}
