#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 13;
const int WHITE = 0;
const int RED = 1;
const int BLUE = 2;

// direction
// 1 오른, 2 왼, 3 위, 4 아래
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};

int N, K;
int color[MAX_SIZE][MAX_SIZE];

// first 말 번호, second 방향
vector<int> board[MAX_SIZE][MAX_SIZE]; // 말 번호가 적혀있음

typedef struct Chessman {
	int y;
	int x;
	int direction;
	Chessman() { }
	Chessman(int y, int x, int direction) :
		y(y), x(x), direction(direction) {}
}Chessman;

Chessman chessman[10];



void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> color[i][j];
		}
	}

	int y, x;
	for (int i = 0; i < K; i++) {
		cin >> y;
		cin >> x;
		chessman[i].y = y;
		chessman[i].x = x;
		board[y][x].push_back(i); // 판에 해당 번호가 저장
		cin >> chessman[i].direction;
	}
}

bool OutOfRange(int y, int x) {
	if (y < 1 || y > N) return true;
	if (x < 1 || x > N) return true;
	return false;
}



void MoveRed(Chessman chm) {
	// 움직임
	int ny = chm.y + dy[chm.direction];
	int nx = chm.x + dx[chm.direction];

	// 이동(역순)
	for (int i = board[chm.y][chm.x].size() - 1; i >= 0; i--) {
		int num = board[chm.y][chm.x][i];
		board[ny][nx].push_back(num);
		chessman[num].y = ny;
		chessman[num].x = nx;
	}
	
	board[chm.y][chm.x].clear(); // 칸 비우기
}

void MoveWhite(Chessman chm) {
	// 움직임
	int ny = chm.y + dy[chm.direction];
	int nx = chm.x + dx[chm.direction];

	// 이동
	for (int i = 0; i < board[chm.y][chm.x].size(); i++) {
		int num = board[chm.y][chm.x][i];
		board[ny][nx].push_back(num);
		chessman[num].y = ny;
		chessman[num].x = nx;
	}
	
	board[chm.y][chm.x].clear(); // 칸 비우기
}

void MoveBlue(Chessman& chm) {
	int& dir = chm.direction;
	if (dir == 1) dir = 2;
	else if (dir == 2) dir = 1;
	else if (dir == 3) dir = 4;
	else if (dir == 4) dir = 3;

	int ny = chm.y + dy[dir];
	int nx = chm.x + dx[dir];

	// 반대 방향도 파랑일 경우
	if (OutOfRange(ny, nx) || color[ny][nx] == BLUE) {
		return;
	}

	// 이동 가능 Red, White
	if (color[ny][nx] == RED) {
		MoveRed(chm);
	} else if (color[ny][nx] == WHITE) {
		MoveWhite(chm);
	}
}



void Move(int chessman_idx) {
	Chessman& chm = chessman[chessman_idx];

	// 자신이 제일 아래칸이 아님 = 움직이지 않음
	if (board[chm.y][chm.x][0] != chessman_idx)
		return;
	
	// 움직임
	int ny = chm.y + dy[chm.direction];
	int nx = chm.x + dx[chm.direction];

	if (OutOfRange(ny, nx)) {
		MoveBlue(chm);
		return;
	}

	switch(color[ny][nx]) {
		case WHITE:
			MoveWhite(chm);
			break;
		case RED:
			MoveRed(chm);
			break;
		case BLUE:
			MoveBlue(chm);
			break;
	}

}

bool MoveAll() {
	// 각 체스들마다 이동
	for (int i = 0; i < K; i++) {
		Move(i);
		if (board[chessman[i].y][chessman[i].x].size() >= 4)
			return false;
	}
	return true;
}


int NewGame() {
	int turn_cnt = 1;

	while(true) 
	{
		if (turn_cnt > 1000)
			return -1;

		if (MoveAll() == false)
			return turn_cnt;

		turn_cnt++;
	}

	return turn_cnt;
}

int main() {
	FastIO();
	Input();
	cout << NewGame();

	return 0;
}
