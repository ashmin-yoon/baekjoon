#include <iostream>
using namespace std;
const int MAX_SIZE = 9;

int T;
int N;
int board[MAX_SIZE][MAX_SIZE];
bool tile[MAX_SIZE+1][MAX_SIZE+1];
bool flag;

void SetNumber(string& position, int number) {
	int r = -1;
	int c = -1;
	r = position[0] - 'A';
	c = position[1] - '1';
	board[r][c] = number;
}

void UseTile(int n1, int n2) {
	tile[n1][n2] = false;
	tile[n2][n1] = false;
}

void UseNotTile(int n1, int n2) {
	tile[n1][n2] = true;
	tile[n2][n1] = true;
}

void SetTile(string& position1, int number1, string& position2, int number2) {
	int r = -1;
	int c = -1;

	r = position1[0] - 'A';
	c = position1[1] - '1';
	board[r][c] = number1;

	r = position2[0] - 'A';
	c = position2[1] - '1';
	board[r][c] = number2;

	UseTile(number1, number2);
}
void Init() {
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			board[i][j] = 0;
			tile[i+1][j+1] = true;
		}
	}

	flag = false;
}

void PrintMap() {
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			cout << board[i][j];
		}
		cout << "\n";
	}
}

void PrintMap(int tc) {
	cout << "Puzzle " << tc << "\n";
	PrintMap();
}

bool PutTileRight(int r, int c, int n1, int n2) {
	board[r][c] = n1;
	board[r][c+1] = n2;
	UseTile(n1, n2);
	return true;
}

bool PutTileDown(int r, int c, int n1, int n2) {
	board[r][c] = n1;
	board[r+1][c] = n2;
	UseTile(n1, n2);

	return true;
}

void RemoveTileRight(int r, int c)
{
	UseNotTile(board[r][c], board[r][c+1]);
	board[r][c] = 0;
	board[r][c+1] = 0;
}

void RemoveTileDown(int r, int c)
{
	UseNotTile(board[r][c], board[r+1][c]);
	board[r][c] = 0;
	board[r+1][c] = 0;
}

bool CheckUsableNumberOfArea(int r, int c, int number) 
{
	r = r / 3 * 3;
	c = c / 3 * 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[r+i][c+j] == number)
				return false;
		}
	}

	return true;
}

bool IsPossibleTileRight(int r, int c, int n1, int n2) {
	// 가로 세로 확인
	for (int i = 0; i < MAX_SIZE; i++)
	{
		// 세로 줄 확인
		if (board[i][c] == n1)
			return false;
		if (board[i][c+1] == n2)
			return false;
		// 가로 줄 확인
		if (board[r][i] == n1)
			return false;
		if (board[r][i] == n2)
			return false;
	}

	// 영역 확인
	if (!CheckUsableNumberOfArea(r, c, n1) || !CheckUsableNumberOfArea(r, c+1, n2))
		return false;

	return true;
}

bool IsPossibleTileDown(int r, int c, int n1, int n2) {

	// 가로 세로 확인
	for (int i = 0; i < MAX_SIZE; i++)
	{
		// 세로 줄 확인
		if (board[i][c] == n1)
			return false;
		if (board[i][c] == n2)
			return false;
		// 가로 줄 확인
		if (board[r][i] == n1)
			return false;
		if (board[r+1][i] == n2)
			return false;
	}

	// 영역 확인
	if (!CheckUsableNumberOfArea(r, c, n1) || !CheckUsableNumberOfArea(r+1, c, n2))
		return false;

	return true;
}


void Solution(int count) {

	if (count == 81)
	{
		PrintMap(T);
		flag = true;
		return;
	}

	if (flag)
		return;

//	cout << "\n";
//	PrintMap(count);

	int r = count / 9;
	int c = count % 9;

	if (board[r][c] != 0)
	{
		Solution(count+1);
		return;
	}


	// 우측으로 블럭 
	if (c < MAX_SIZE-1 && board[r][c+1] == 0)
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int j = i + 1; j <= 9; j++)
			{
				if (!tile[i][j]) continue;

				int n1 = i;
				int n2 = j;

				// 우측 방향 타일
				if (IsPossibleTileRight(r, c, n1, n2))
				{
					PutTileRight(r, c, n1, n2);
					Solution(count+1);
					RemoveTileRight(r, c);
				}

				if (IsPossibleTileRight(r, c, n2, n1))
				{
					PutTileRight(r, c, n2, n1);
					Solution(count+1);
					RemoveTileRight(r, c);
				}
			}
		}
	}


	// 아래로 블럭
	if (r < MAX_SIZE-1 && board[r+1][c] == 0)
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int j = i + 1; j <= 9; j++)
			{
				if (!tile[i][j]) continue;
				int n1 = i;
				int n2 = j;

				if (IsPossibleTileDown(r, c, n1, n2))
				{
					PutTileDown(r, c, n1, n2);
					Solution(count+1);
					RemoveTileDown(r, c);
				}

				if (IsPossibleTileDown(r, c, n2, n1))
				{
					PutTileDown(r, c, n2, n1);
					Solution(count+1);
					RemoveTileDown(r, c);
				}
			}
		}
	}


}



int main() {

	T = 1;
	while(true)
	{
		cin >> N; // 채워진 도미노 개수
		if (N == 0)
			break;

		Init();

		// ======= input =======
		string pos;
		string pos2;
		int number;
		int number2;
		for (int i = 0; i < N; i++)
		{
			cin >> number;
			cin >> pos;
			cin >> number2;
			cin >> pos2;
			SetTile(pos, number, pos2, number2);
		}

		for (int i = 1; i <= 9; i++)
		{
			cin >> pos;
			SetNumber(pos, i);
		}
		// ======= input =======
		

		Solution(0);
		T++;
	}


	return 0;
}
