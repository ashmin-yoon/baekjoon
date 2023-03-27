#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_SIZE = 9;

typedef struct Position {
	int y;
	int x;
	Position() {}
	Position(int y, int x) : y(y), x(x) {}

	bool operator<(const Position &p) {
		if (this->y < p.y)
			return true;
		else if (this->y < p.y)
		{
			return this->x < p.x;
		}
		return false;
	}
} Position;

typedef int relation_count;


int N;
int board[MAX_SIZE][MAX_SIZE];
vector<pair<int, int> > v;
vector<pair<int, int> > rowSequence;
vector<pair<Position, relation_count> > sequence;
int spaceCountRow[MAX_SIZE];
int spaceCountCol[MAX_SIZE];
int spaceCountArea[MAX_SIZE]; 
bool visited[MAX_SIZE][MAX_SIZE];
bool exitFlag = false;


// 0, 1, 2
// 3, 4, 5
// 6, 7, 8



bool seq_cmp(pair<Position, relation_count> &a, pair<Position, relation_count> &b);
void Input();
void PrintBoard();
void GetUsableNumbers(int y, int x, vector<int>& v);
void SetAllSequence();


void Solution(int count) {


	if (exitFlag)
		return;

	if (count == sequence.size()) {
		PrintBoard();
		exitFlag = true;
		return;
	}

	cout << count << "\n";
	PrintBoard();
	cout << "\n\n";



	int i = count;
	//for (int i = count; i < sequence.size(); i++)
	//{
		int y = sequence[i].first.y;
		int x = sequence[i].first.x;

		//if (visited[y][x]) continue;
		visited[y][x] = true;

		vector<int> usable;
		GetUsableNumbers(y, x, usable);
			for (int j = 0; j < usable.size(); j++)
			{
				board[y][x] = usable[j];
				Solution(count+1);
			}

		visited[y][x] = false;
		board[y][x] = 0;

//	}

}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);


	Input();

	// 연관관계가 적은 위치부터 처리
	SetAllSequence(); 


	Solution(0); 			// 설정된 순서로 Brute Force 진행
	//PrintBoard();



	return 0;
}


void SetAllSequence() {
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			if (board[i][j] != 0) continue;
			sequence.push_back(make_pair(Position(i, j), 0));
		}
	}

	for (int i = 0; i < sequence.size(); i++)
	{
		int y = sequence[i].first.y;
		int x = sequence[i].first.x;
		int area =  y / 3 * 3 + x / 3;

		sequence[i].second = spaceCountArea[area] + spaceCountRow[y] + spaceCountCol[x];
	}

	sort(sequence.begin(), sequence.end(), seq_cmp);
}

void PrintBoard() {
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}


void Input() {
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
			{
				v.push_back(make_pair(i, j));
				spaceCountRow[i]++;
				spaceCountCol[j]++;
				spaceCountArea[((i / 3) * 3) + j / 3]++; // 해당 구역
				N++;
			}
		}
	}
}

bool seq_cmp(pair<Position, relation_count> &a, pair<Position, relation_count> &b) {
	// first = Position y, x
	// second = relation_count;

	if (a.second < b.second)
		return true;
	else if (a.second == b.second)
		return a.first < b.first; // 같다면 y 작은 순, 
		//return true;
	else 
		return false;
}

void GetUsableNumbers(int y, int x, vector<int>& v) {
	bool bNum[MAX_SIZE + 1];
	memset(bNum, true, MAX_SIZE + 1);

	int num;
	// 해당 열 확인
	for (int i = 0; i < MAX_SIZE; i++)
	{
		num = board[i][x];
		bNum[num] = false;
	}


	// 해당 행 확인
	for (int j = 0; j < MAX_SIZE; j++)
	{
		num = board[y][j];
		bNum[num] = false;
	}

	// 영역 확인
	int area = y / 3 * 3 + x / 3;

	y = y / 3 * 3;
	x = x / 3 * 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			num = board[y+i][x+j];
			bNum[num] = false;
		}
	}
	
	for (int i = 1; i <= MAX_SIZE; i++)
	{
		if (bNum[i])
			v.push_back(i);
	}
}


