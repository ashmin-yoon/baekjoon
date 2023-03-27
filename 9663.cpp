#include <iostream>
using namespace std;
const int MAX_SIZE = 15;

int N;
bool board[MAX_SIZE][MAX_SIZE];
int ans;

bool OutofIndex(int r, int c) {
	if (r < 0 || r >= N) return true;
	if (c < 0 || c >= N) return true;
	return false;
}

void PrintMap() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool IsPossible(int r, int c) {
	// 이전 라인들만 확인

	// 세로축 확인
	for (int i = 0; i < r; i++)
	{
		if (board[i][c])
			return false;
	}

	// 대각선 확인(좌)
	for (int i = 1; i <= r; i++)
	{
		if (OutofIndex(r-i, c-i))
			break;
		if (board[r-i][c-i])
			return false;
	}

	// 대각선 확인(우)
	for (int i = 1; i <= r; i++)
	{
		if (OutofIndex(r-i, c+i))
			break;
		if (board[r-i][c+i])
			return false;
	}

	return true;
}

void Solution(int count) {
	//PrintMap();
	if (count == N)
	{
		ans++;
		return;
	}

	int i = count;
	for (int j = 0; j < N; j++)
	{
		if (!IsPossible(i,j)) continue;
		board[i][j] = true;
		Solution(count+1);
		board[i][j] = false;
	}
}


int main() {

	cin >> N;
	Solution(0);
	
	cout << ans;
	return 0;
}
