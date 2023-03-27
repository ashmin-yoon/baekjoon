#include <iostream>
using namespace std;
const int MAX_SIZE = 50;

int N, M;
char board[MAX_SIZE][MAX_SIZE];

int visited[MAX_SIZE][MAX_SIZE];
bool isCycle = false;

int dy[4] = {0, 1, 0, -1}; // 우, 아래, 좌, 위
int dx[4] = {1, 0, -1, 0};

void dfs(int count, int y, int x) {

	if (isCycle) return;
	if (visited[y][x]) return;
	visited[y][x] = count;

	//cout << "(" << y << ", " << x << ") " << count << endl;

	for (int i = 0; i < 4; i++)
	{
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		// 범위 검사, 다른색 검사
		if (next_y < 0 || next_y >= N) continue;
		if (next_x < 0 || next_x >= M) continue;
		if (board[y][x] != board[next_y][next_x]) continue;
		if (visited[next_y][next_x]) 
		{
			// 종료 조건 검사
			if (visited[next_y][next_x] - count >= 3) //  4 <= k
			{
				isCycle = true;	
				//cout << "발견 ";
				//cout << "(" << y << ", " << x << ") " << count << endl;
				break;
			}
			continue;
		}
		dfs(count + 1, next_y, next_x);
	}
}

int main() {
	cin >> N >> M;

	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			board[i][j] = str[j];
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			dfs(1, i, j);
		}
	}

	if (isCycle) cout << "Yes";
	else cout << "No";

	return 0;
}
