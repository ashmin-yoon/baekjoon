#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 13;
const int WHITE = 0;
const int RED = 1;
const int BLUE = 2;

int N, K;

// 1 오른, 2 왼, 3 위, 4 아래
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};

// 17780 새로운 게임과 다른점 <- 가장 아래칸 말만 이동 가능
// 이 문제는 상관없이 이동 가능

int color[MAX_SIZE][MAX_SIZE];
vector<int> board[MAX_SIZE][MAX_SIZE];
bool isOver;

typedef struct Chessman {
	int y;
	int x;
	int dir;
	Chessman() {
		y = 0; x = 0; dir = 0;
	}
	Chessman(int y, int x, int dir) :
		y(y), x(x), dir(dir) {}
}Chessman;

Chessman chessman[10]; // 체스 말 정보

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> K;

	// 보드판 색
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> color[i][j];
		}
	}

	// 말 정보
	int y, x;
	for (int i = 0; i < K; i++) {
		cin >> y >> x;
		cin >> chessman[i].dir;
		chessman[i].y = y;
		chessman[i].x = x;
		board[y][x].push_back(i);
	}
}

bool OutOfRange(int y, int x) {
	if (y < 1 || y > N) return true;
	if (x < 1 || x > N) return true;
	return false;
}

bool CheckGameOver(int chessman_idx) {
	int y = chessman[chessman_idx].y;
	int x = chessman[chessman_idx].x;

	if (board[y][x].size() >= 4) {
		return true;
	}

	return false;
}



vector<int>& GetVector(int y, int x) {
	return board[y][x];
}

int FindMyIndex(int chm_idx) {
	int y = chessman[chm_idx].y;
	int x = chessman[chm_idx].x;

	vector<int>& v = GetVector(y, x);

	int my_idx = 0;
	for (int i = 0; i < v.size(); i++) {
		// 자기 자신 찾기
		if (v[i] == chm_idx) {
			my_idx = i;
			return my_idx;
		}
	}

	return -1;
}

void Erase(vector<int>& v, int my_idx) {
	v.erase(v.begin() + my_idx, v.end());  // 지우기
}

void MoveRedOrWhite(int chm_idx, int move_color) {
	Chessman& chm = chessman[chm_idx];
	int ny = chm.y + dy[chm.dir];
	int nx = chm.x + dx[chm.dir];


	vector<int>& v = GetVector(chm.y, chm.x);
	vector<int>& nv = GetVector(ny, nx);
	int my_idx = FindMyIndex(chm_idx);



	if (move_color == WHITE) {
		// 자기자신 ~ 위로
		for (int i = my_idx; i < v.size(); i++) {
			nv.push_back(v[i]);
			chessman[v[i]].y = ny;
			chessman[v[i]].x = nx;
		}
	}

	if (move_color == RED) {
		// 제일 위에서 ~  자기자신
		for (int i = v.size() - 1; i >= my_idx; i--) {
			nv.push_back(v[i]);
			chessman[v[i]].y = ny;
			chessman[v[i]].x = nx;
		}
	}

	Erase(v, my_idx);
}

void MoveBlue(int chm_idx) {
	Chessman& chm = chessman[chm_idx];
	int ndir = 0;
	if (chm.dir == 1) ndir = 2;
	else if (chm.dir == 2) ndir = 1;
	else if (chm.dir == 3) ndir = 4;
	else if (chm.dir == 4) ndir = 3;
	chm.dir = ndir;

	int ny = chm.y + dy[ndir];
	int nx = chm.x + dx[ndir];

	// 가만히 있음
	if (OutOfRange(ny, nx) || color[ny][nx] == BLUE) {
		return;
	}

	switch (color[ny][nx]) {
		case WHITE:
			MoveRedOrWhite(chm_idx, WHITE);
			break;
		case RED:
			MoveRedOrWhite(chm_idx, RED);
			break;
	}
}

void Move(int chm_idx) {
	Chessman& chm = chessman[chm_idx];
	int ny = chm.y + dy[chm.dir];
	int nx = chm.x + dx[chm.dir];

	if (OutOfRange(ny, nx)) {
		MoveBlue(chm_idx);
		return;
	}

	switch (color[ny][nx]) {
		case WHITE:
			MoveRedOrWhite(chm_idx, WHITE);
			break;
		case BLUE:
			MoveBlue(chm_idx);
			break;
		case RED:
			MoveRedOrWhite(chm_idx, RED);
			break;
	}
}

void MoveAll() {
	for (int i = 0; i < K; i++) {
		Move(i);
		isOver = CheckGameOver(i);
		if (isOver)
			return;
	}
}

int NewGame2() {
	int turn = 1;

	while(true) {
		if (turn > 1000)
			return -1; 

		MoveAll();
		if (isOver)
			break;

		turn++;
	}	

	return turn;
}

int main() {
	FastIO();
	Input();
	cout << NewGame2();


	return 0;
}
