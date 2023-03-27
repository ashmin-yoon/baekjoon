#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 20;

int board[MAX_SIZE][MAX_SIZE];
int tmpBoard[MAX_SIZE][MAX_SIZE];

int N;
int ans;
bool combineAvailable[MAX_SIZE];

typedef struct Block {
	int y;
	int x;
	int value;
	Block(int y, int x, int value)
	{
		this->y = y;
		this->x = x;
		this->value = value;
	}
} Block;


queue<vector<Block> > q;
queue<int> countQueue;

void ClearBoard() {

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = 0;
			tmpBoard[i][j] = 0;
		}
	}
}

void SetBoard(vector<Block> &v) {
	for (int i = 0; i < v.size(); i++)
		{
			int y = v[i].y;
			int x = v[i].x;
			board[y][x] = v[i].value;
		}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tmpBoard[i][j] = board[i][j];
		}
	}
}

void PrintBoard() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

void InitCombineAvailable() {
	for (int i = 0; i < N; i++)
	{
		combineAvailable[i] = true;
	}
}

void PushQueue(int cnt) {
	vector<Block> v;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] != 0)
			{
				v.push_back(Block(i, j, board[i][j]));
			}
		}
	}
	q.push(v);
	countQueue.push(cnt);
}

void LoadTmpBoardToBoard() {

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = tmpBoard[i][j];
		}
	}
}

bool Left() {
	int moveCnt = 0;
	InitCombineAvailable();
	LoadTmpBoardToBoard();
	
	// 열 단위 기준으로 진행
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (board[i][j] == 0) {
				continue;
			}

			// value 있음
			int k;
			for (k = j - 1; k >= 0; k--)
			{
				if (board[i][k] == 0)
				{
					board[i][k] = board[i][k+1];
					board[i][k+1] = 0;
					moveCnt++;
					continue;
				}
				// 왼쪽으로 이동할 때 만나는 블럭이 같은 경우
				else if (board[i][k] == board[i][k+1])
				{
					if (!combineAvailable[i]) // 합칠 수 없는 경우
					{
						combineAvailable[i] = true;
						break;
					}
					board[i][k] *= 2;
					board[i][k+1] = 0;
					combineAvailable[i] = false;
					moveCnt++;
					break;
				} 
				else  // 다른 블럭인 경우
				{
					combineAvailable[i] = true; // 합치지 않고 다른 블럭을 만나 끝난 경우
					break;
				}
			}

		}
	}

	if (moveCnt == 0)
		return false;
	return true;
}

bool Right() {
	InitCombineAvailable();
	LoadTmpBoardToBoard();
	int moveCnt = 0;
	// 열 단위 기준으로 진행
	for (int j = N-1; j >= 0; j--)
	{
		for (int i = 0; i < N; i++)
		{
			if (board[i][j] == 0) {
				continue;
			}

			// value 있음
			int k;
			for (k = j + 1; k < N; k++)
			{
				if (board[i][k] == 0)
				{
					board[i][k] = board[i][k-1];
					board[i][k-1] = 0;
					moveCnt++;	
					continue;
				}
				// 왼쪽으로 이동할 때 만나는 블럭이 같은 경우
				else if (board[i][k] == board[i][k-1])
				{
					if (!combineAvailable[i]) // 합칠 수 없는 경우
					{
						combineAvailable[i] = true;
						break;
					}
					board[i][k] *= 2;
					board[i][k-1] = 0;
					combineAvailable[i] = false;
					moveCnt++;	
					break;
				} 
				else  // 다른 블럭인 경우
				{
					combineAvailable[i] = true; // 합치지 않고 다른 블럭을 만나 끝난 경우
					break;
				}
			}

		}
	}

	if (moveCnt == 0)
		return false;
	return true;
}

bool Up() {
	InitCombineAvailable();
	LoadTmpBoardToBoard();
	// 행 단위 기준으로 진행
	int moveCnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 0) {
				continue;
			}

			// value 있음
			int k;
			for (k = i - 1; k >= 0; k--)
			{
				if (board[k][j] == 0)
				{
					board[k][j] = board[k+1][j];
					board[k+1][j] = 0;
					moveCnt++;	
					continue;
				}
				// 왼쪽으로 이동할 때 만나는 블럭이 같은 경우
				else if (board[k][j] == board[k+1][j])
				{
					if (!combineAvailable[j]) // 합칠 수 없는 경우
					{
						combineAvailable[j] = true;
						break;
					}
					board[k][j] *= 2;
					board[k+1][j] = 0;
					combineAvailable[j] = false;
					break;
				} 
				else  // 다른 블럭인 경우
				{
					combineAvailable[j] = true; // 합치지 않고 다른 블럭을 만나 끝난 경우
					break;
				}
			}

		}
	}

	if (moveCnt == 0)
		return false;

	return true;

}

bool Down() {
	InitCombineAvailable();
	LoadTmpBoardToBoard();
	// 행 단위 기준으로 진행
	int moveCnt = 0;

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 0) {
				continue;
			}

			// value 있음
			int k;
			for (k = i + 1; k < N; k++)
			{
				if (board[k][j] == 0)
				{
					board[k][j] = board[k-1][j];
					board[k-1][j] = 0;
					moveCnt++;
					continue;
				}
				// 왼쪽으로 이동할 때 만나는 블럭이 같은 경우
				else if (board[k][j] == board[k-1][j])
				{
					if (!combineAvailable[j]) // 합칠 수 없는 경우
					{
						combineAvailable[j] = true;
						break;
					}
					board[k][j] *= 2;
					board[k-1][j] = 0;
					combineAvailable[j] = false;
					moveCnt++;
					break;
				} 
				else  // 다른 블럭인 경우
				{
					combineAvailable[j] = true; // 합치지 않고 다른 블럭을 만나 끝난 경우
					break;
				}
			}

		}
	}

	if (moveCnt == 0)
	{
		return false;
	}
	return true;



}


void SearchMaxValue() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ans = max(ans, board[i][j]);
		}
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	vector<Block> v;
	int number;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> number;
			if (number != 0)
			{
				v.push_back(Block(i, j, number));
			}
		}
	}

	q.push(v);
	countQueue.push(0);
	SearchMaxValue();

	while(!q.empty())
	{
		ClearBoard();		
		v.clear();

		SetBoard(q.front());
		int cnt = countQueue.front();

		q.pop();
		countQueue.pop();

		if (cnt > 5)
			break;

		PrintBoard();
		SearchMaxValue();



		// q.push는 각 위치에서 수행
		if (Left()) PushQueue(cnt+1);
		if (Right()) PushQueue(cnt+1); 
		if (Up()) PushQueue(cnt+1);
		if (Down()) PushQueue(cnt+1);

	}

	cout << ans;

	return 0;
}
