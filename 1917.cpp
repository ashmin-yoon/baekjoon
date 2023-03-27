#include <iostream>
using namespace std;
const int MAX_SIZE = 6;

int N = 6;
int M = 6;
int startY = -1;
int startX = -1;
int counting[6];

int dy[4] = {0, -1, 0, 1}; // left, up, right, down
int dx[4] = {-1, 0, 1, 0};
int arr[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

// 내 주사위를 맵에 굴린다는 생각
// 주사위에는 숫자(count 인덱스)가 적혀있음
int dice[6];

enum Position {
	NONE = -1,
	BOTTOM,
	FRONT,
	TOP,
	BACK,
	LEFT,
	RIGHT
};


enum Direction {
	DIRECTION_NONE = -1,
	DIRECTION_LEFT,
	DIRECTION_UP,
	DIRECTION_RIGHT,
	DIRECTION_DOWN
};



int diceMoveLeft() {
	int tmp = dice[RIGHT];
	dice[RIGHT] = dice[BOTTOM];
	dice[BOTTOM] = dice[LEFT];
	dice[LEFT] = dice[TOP];
	dice[TOP] = tmp;

	return dice[BOTTOM];
}

int diceMoveRight() {
	int tmp = dice[RIGHT];
	dice[RIGHT] = dice[TOP];
	dice[TOP] = dice[LEFT];
	dice[LEFT] = dice[BOTTOM];
	dice[BOTTOM] = tmp;

	return dice[BOTTOM];
}

int diceMoveUp() {
	int tmp = dice[BOTTOM];
	dice[BOTTOM] = dice[BACK];
	dice[BACK] = dice[TOP];
	dice[TOP] = dice[FRONT];
	dice[FRONT] = tmp;

	return dice[BOTTOM];
}

int diceMoveDown() {
	int tmp = dice[BOTTOM];
	dice[BOTTOM] = dice[FRONT];
	dice[FRONT] = dice[TOP];
	dice[TOP] = dice[BACK];
	dice[BACK] = tmp;

	return dice[BOTTOM];
}


void init() {
	startY = -1;
	startX = -1;
	for (int i = 0; i < 6; i++)
	{
		counting[i] = 0;
		dice[i] = i;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			visited[i][j] = false;
			arr[i][j] = 0;
		}
	}
}

bool outOfRange(int y, int x) {
	if (y < 0 || y >= MAX_SIZE) return true;
	if (x < 0 || x >= MAX_SIZE) return true;
	return false;
}


void MoveDice(Direction direction) {
	switch(direction)
	{
		case DIRECTION_LEFT:
			diceMoveLeft();
			break;
		case DIRECTION_UP:
			diceMoveUp();
			break;
		case DIRECTION_RIGHT:
			diceMoveRight();
			break;
		case DIRECTION_DOWN:
			diceMoveDown();
			break;
		default:
			break;
	}
}

void DiceRollback(Direction direction)
{
	switch(direction)
	{
		case DIRECTION_LEFT:
			diceMoveRight();
			break;
		case DIRECTION_UP:
			diceMoveDown();
			break;
		case DIRECTION_RIGHT:
			diceMoveLeft();
			break;
		case DIRECTION_DOWN:
			diceMoveUp();
			break;
		default:
			break;
	}
}

void dfs(int y, int x) {
	
	
	if (visited[y][x]) return;

	counting[dice[BOTTOM]]++;
	visited[y][x] = true;

	// 이동
	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (outOfRange(nextY, nextX)) continue;
		if (visited[nextY][nextX] || arr[nextY][nextX] == 0) continue;
		
		Direction direction;
		switch(i)
		{
			case DIRECTION_LEFT:
				direction = DIRECTION_RIGHT;
				break;
			case DIRECTION_UP:
				direction = DIRECTION_DOWN;
				break;
			case DIRECTION_RIGHT:
				direction = DIRECTION_LEFT;
				break;
			case DIRECTION_DOWN:
				direction = DIRECTION_UP;
				break;
		}

		MoveDice(direction);
		dfs(nextY, nextX);
		DiceRollback(direction);
	}
}

int main() {

	cin.tie(nullptr);

	int T = 3;
	while(T--)
	{
		// init
		init();

		// input
		bool isStart = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> arr[i][j];
				if (!isStart && arr[i][j]) 
				{
					isStart = true;
					startY = i;
					startX = j;
				}
			}
		}

		dfs(startY, startX);


		bool ans = true;
		for (int i = 0; i < 6; i++)
		{
			if (counting[i] != 1)
			{
				ans = false;
				break;
			}
		}

		if (ans)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}
