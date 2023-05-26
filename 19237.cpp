#include <iostream>
#include <queue>
using namespace std;
const int MAX_SIZE = 20;
const int SHARK_MAX_SIZE = MAX_SIZE * MAX_SIZE + 1;

// 구현 문제 너무 싫다..
// 하지만 일정 수준의 문제들은 연습용으로 풀기

// 6% 틀림
// time 조건 때문..

int N, M, K;
int aliveCount = 0;

typedef struct Info {
	int shk_num;
	int smell;
}Info;

typedef struct Shark {
	int y;
	int x;
	int dir;
	bool isAlive;
	int shk_num; // 예약 큐 때문에 추가

	Shark() {
		isAlive = false;
		y = 0;
		x = 0;
		dir = 0;
		shk_num = 0;
	}

	Shark(int y, int x, int dir, int shk_num) {
		this->y = y;
		this->x = x;
		this->dir = dir;
		this->shk_num = shk_num;
		isAlive = true;
	}

}Shark;

Info board[MAX_SIZE][MAX_SIZE];

queue<Shark> reservationQueue; // 이동 예약용 큐

// 1위, 2아래, 3왼, 4오
int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, -1, 1};

int prefer[SHARK_MAX_SIZE][5][4]; // [상어번호][현재방향][우선순위순서]

Shark shark[MAX_SIZE * MAX_SIZE + 1];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> M >> K;
	aliveCount = M;
	
	// 상어 번호
	int shk_num;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> shk_num;
			board[i][j].shk_num = shk_num;
			// 상어 번호가 있을 때
			if (shk_num > 0) {
				board[i][j].smell = K; // 냄새 K
				shark[shk_num].y = i;
				shark[shk_num].x = j;
				shark[shk_num].isAlive = true;
				shark[shk_num].shk_num = shk_num;
			}
		}
	}

	// 상어 방향
	for (int shk = 1; shk <= M; shk++) {
		cin >> shark[shk].dir;
	}

	// 상어 방향 우선순위
	for (int shk = 1; shk <= M; shk++) {
		for (int dir = 1; dir <= 4; dir++) {
			for (int j = 0; j < 4; j++) {
				cin >> prefer[shk][dir][j];
			}
		}
	}
}

bool OutOfRange(int y, int x) {
	if (y < 0 || y >= N) return true;
	if (x < 0 || x >= N) return true;
	return false;
}

void PrintBoard(int t) {
	printf("PrintBoard, time = %d\n", t);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("(%d, %d) ", board[i][j].shk_num, board[i][j].smell);
		}
		printf("\n");
	}
	printf("\n");
}

void DownSmell() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// DownSmell에서 0으로 만들면 이동상 오류로 따로 처리
			int shk = board[i][j].shk_num;

			int y = shark[shk].y;
			int x = shark[shk].x;

			// 현재 상어가 위치한 곳
			if (y == i && x == j && shark[shk].isAlive) 
				continue; 

			// 이전의 위치
			if (board[i][j].smell > 0) {
				board[i][j].smell--;
			}

			if (board[i][j].smell == 0) {
				board[i][j].shk_num = 0;
			}
		}
	}
}


// 빈칸 이동
// 겹칠 수 있기에 이동 예약으로 처리
bool MoveEmpty(int shk) {
	int& y =  shark[shk].y;
	int& x = shark[shk].x;
	int& dir = shark[shk].dir;
	bool isMoved = false;

	for (int i = 0; i < 4; i++) {
		int ndir = prefer[shk][dir][i];
		int ny = y + dy[ndir];
		int nx = x + dx[ndir];

		if (OutOfRange(ny, nx)) continue;
		if (board[ny][nx].smell != 0) continue;

		// 이동 예약
		reservationQueue.push(Shark(ny, nx, ndir, shk));
		isMoved = true;
		break;

	}

	return isMoved;
}

// 자기 영역 이동
bool MoveSelfArea(int shk) {
	int& y =  shark[shk].y;
	int& x = shark[shk].x;
	int& dir = shark[shk].dir;
	bool isMoved = false;

	for (int i = 0; i < 4; i++) {
		int ndir = prefer[shk][dir][i];
		int ny = y + dy[ndir];
		int nx = x + dx[ndir];

		if (OutOfRange(ny, nx)) continue;

		// 이동 실시	
		if (board[ny][nx].shk_num == shk) {
			y = ny;
			x = nx;
			dir = ndir;
			board[y][x].smell = K; // 냄새 갱신
			board[y][x].shk_num = shk; // board 상어 갱신
			isMoved = true;
			break;
		}
	}

	return isMoved;
}

void MoveShark(int shk) {
	// 상어 없음
	if (!shark[shk].isAlive)
		return;

	bool isMoved = false;
	isMoved = MoveEmpty(shk);

	// 빈 공간 이동 성공
	if (isMoved) {
		return;
	}

	// 자기 공간 이동
	MoveSelfArea(shk);
}

void Move() {

	for (int shk = 1; shk <= M; shk++) {
		MoveShark(shk);
	}

}

void ExecuteReservationMoving() {

	while (!reservationQueue.empty()) {
		Shark shk = reservationQueue.front();
		reservationQueue.pop();
		int shk_num = shk.shk_num;
		int board_shk_num = board[shk.y][shk.x].shk_num;

		// 현재 이동하려는 위치에 낮은 번호 상어가 존재
		// 자신 쫓겨남
		if (board_shk_num != 0 && board_shk_num < shk.shk_num) {
			shark[shk_num].isAlive = false;
			aliveCount--;
			continue;
		}

		shark[shk_num] = shk; // 상어 정보 갱신

		// board 갱신
		board[shk.y][shk.x].smell = K;
		board[shk.y][shk.x].shk_num = shk.shk_num;
	}
}

int Solution() {
	//cout << "Solution\n";
	int t = 1;

	while (true) {
		//PrintBoard(t);

		// 시간 초과
		if (t > 1000)
			return -1;

		Move();
		ExecuteReservationMoving();
		DownSmell();

		// 종료 조건
		if (aliveCount == 1)
			break;

		t++;
	}

	return t;
}

int main() {
	FastIO();
	Input();
	cout << Solution();

	return 0;
}
