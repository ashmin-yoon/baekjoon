#include <iostream>
#include <queue>
using namespace std;
const int MAX_SIZE = 10;


int N, M;
char board[MAX_SIZE][MAX_SIZE];

// red y, x, blue y, x
bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];

int pre_ry;
int pre_rx;
int pre_by;
int pre_bx;

int ry;
int rx;

int by;
int bx;


queue<pair<int, int> > redQueue;
queue<pair<int, int> > blueQueue;
queue<int> countQueue;

enum Direction {
	LEFT,
	UP,
	RIGHT,
	DOWN
};

// 더이상 못 움직일 때까지 이동
const char WALL = '#';

void Input() {
	cin >> N >> M;

	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == 'B')
			{
				pre_by = i;
				pre_bx = j;
			}
			if (str[j] == 'R')
			{
				pre_ry = i;
				pre_rx = j;
			}
			board[i][j] = str[j];

		}
	}
}



int GetMovingCount(int y, int x, Direction dir) {
	
	int count = 0;
	bool fall = false;
	bool equalLine = false;
	if (dir == UP)
	{
		for (int i = 1; board[y-i][x] != WALL; i++)
		{
			if (board[y-i][x] == 'R' || board[y-i][x] == 'B')
			{
				equalLine = true;
				continue;
			}
			count++;
			if (board[y-i][x] == 'O')
			{
				fall = true;
				break;
			}
		}

		if (fall && equalLine)
			count++;
	}



	if (dir == LEFT)
	{
		for (int i = 1; board[y][x-i] != WALL; i++)
		{
			if (board[y][x - i] == 'R' || board[y][x - i] == 'B')
			{
				equalLine = true;
				continue;
			}
			count++;
			if (board[y][x - i] == 'O')
			{
				fall = true;
				break;
			}
		}

		if (fall && equalLine)
			count++;
	}

	if (dir == RIGHT)
	{
		for (int i = 1; board[y][x+i] != WALL; i++)
		{
			if (board[y][x + i] == 'R' || board[y][x + i] == 'B')
			{
				equalLine = true;
				continue;
			}
			count++;
			if (board[y][x + i] == 'O')
			{
				fall = true;
				break;
			}
		}

		if (fall && equalLine)
			count++;
	}


	if (dir == DOWN)
	{
		for (int i = 1; board[y+i][x] != WALL; i++)
		{
			if (board[y + i][x] == 'R' || board[y + i][x] == 'B')
			{
				equalLine = true;
				continue;
			}
			count++;
			if (board[y + i][x] == 'O')
			{
				fall = true;
				break;
			}
		}

		if (fall && equalLine)
			count++;
	}

	return count;
}

void RemoveRedAndBlueFromBoard() 
{
	if (board[pre_ry][pre_rx] != 'O')
		board[pre_ry][pre_rx] = '.';

	if (board[pre_by][pre_bx] != 'O')
		board[pre_by][pre_bx] = '.';
}

void PrintBoard() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << board[i][j];
		}
		cout << "\n";
	}
		cout << "\n";
		cout << "\n";
}

void PrintingRedAndBlue() {
	if (board[ry][rx] != 'O')
		board[ry][rx] = 'R';
	if (board[by][bx] != 'O')
		board[by][bx] = 'B';
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	
	redQueue.push(make_pair(pre_ry, pre_rx));
	blueQueue.push(make_pair(pre_by, pre_bx));
	countQueue.push(0);

	// 10번 이하 일 경우만
	int ans = -1;

	while(!redQueue.empty()) {
		RemoveRedAndBlueFromBoard();
		ry = redQueue.front().first;
		rx = redQueue.front().second;

		by = blueQueue.front().first;
		bx = blueQueue.front().second;

		PrintingRedAndBlue();
		
		pre_ry = ry;
		pre_rx = rx;
		pre_by = by;
		pre_bx = bx;


		int movingCount = countQueue.front();
		redQueue.pop();
		blueQueue.pop();
		countQueue.pop();

		if (visited[ry][rx][by][bx]) continue;
		visited[ry][rx][by][bx] = true;

//		cout << "red(" << ry << ", " << rx << ")\t";
//		cout << "blue(" << by << ", " << bx << ")\t";
//		cout << movingCount << "\n";
//		PrintBoard();

		if (movingCount > 10)
		{
			ans = -1;
			break;
		}

		if (board[ry][rx] == 'O' && board[by][bx] != 'O')
		{
			ans = movingCount;
			break;
		}


		if (board[by][bx] == 'O')
		{
			//cout << "blue 구멍에 빠짐\n";
			continue;
		}



		// 왼

		

		// 4 방향 이동에 따른 카운트 큐 push
		for (int i = 0; i < 4; i++)
		{
			countQueue.push(movingCount + 1);
		}

		// 이동 가능한 칸 수
		int count = 0;
		// left
		count = GetMovingCount(ry, rx, LEFT);
		redQueue.push(make_pair(ry, rx - count));

		count = GetMovingCount(by, bx, LEFT);
		blueQueue.push(make_pair(by, bx - count));

		// right
		count = GetMovingCount(ry, rx, RIGHT);
		redQueue.push(make_pair(ry, rx + count));

		count = GetMovingCount(by, bx, RIGHT);
		blueQueue.push(make_pair(by, bx + count));


		// up
		count = GetMovingCount(ry, rx, UP);
		redQueue.push(make_pair(ry - count, rx));

		count = GetMovingCount(by, bx, UP);
		blueQueue.push(make_pair(by - count, bx));

		// down
		count = GetMovingCount(ry, rx, DOWN);
		redQueue.push(make_pair(ry + count, rx));

		count = GetMovingCount(by, bx, DOWN);
		blueQueue.push(make_pair(by + count, bx));
	}

	cout << ans;

	return 0;
}
