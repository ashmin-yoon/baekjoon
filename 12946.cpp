#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 50;

bool isColor[MAX_SIZE][MAX_SIZE];
int colorNumber[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int kindOfColors = 0;
int N;


// 현재칸 기준 - 좌상, 우상, 좌,  우, 좌하단, 우하단
int dy[6] = {-1, -1, 0, 0, 1, 1};
int dx[6] = {0, 1, -1, 1, -1, 0};


// 반례가 무엇인지 알고 적절한 최대 3인 것도 알았지만
// 적절한 풀이법이 떠오르지 않아 다른 사람 풀이법 봄

// 풀이법 참고하여 다 맞는 것 같은데
// 정확히 어떤 부분에서 틀린지 모르겠음.
// 주변 색 확인할 때 OutOfRange 빠트림


bool OutOfRange(int y, int x)
{
	if (y < 0 || y >= N) return true;
	if (x < 0 || x >= N) return true;

	return false;
}


void DFS(int y, int x) {

	visited[y][x] = true;
	if (kindOfColors >= 3) return;


	// 가능한 색상 확인 
	for (int c = 1; c <= kindOfColors; c++)
	{
		bool isAvailableColor = true;
		for (int i = 0; i < 6; i++)
		{
			int neighbor_y = y + dy[i];
			int neighbor_x = x + dx[i];
			if (OutOfRange(neighbor_y, neighbor_x)) continue; // index 검사
			if (colorNumber[neighbor_y][neighbor_x] == c) // 이웃 색상과 같으면 다음 색상 확인
			{
				isAvailableColor = false;
				break;
			}
		}

		// 색칠 가능하다면 색칠
		if (isAvailableColor)
		{
			colorNumber[y][x] = c;
			break;
		}
	}

	// 색칠 되지 않았다면 색상 추가 후 색칠
	if (colorNumber[y][x] == 0)
	{
		kindOfColors++;
		colorNumber[y][x] = kindOfColors;
	}


	// DFS 재귀
	for (int i = 0; i < 6; i++)
	{
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (OutOfRange(next_y, next_x)) continue;
		if (!isColor[next_y][next_x]) continue;
		if (visited[next_y][next_x]) continue; 		// 방문 여부

		DFS(next_y, next_x);
	}

}



int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char ch;
		for (int j = 0; j < N; j++)
		{
			cin >> ch;
			if (ch == 'X') isColor[i][j] = true;
			else isColor[i][j] = false;
		}
	}


	// 그냥 진행
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (isColor[i][j] && !visited[i][j])
				DFS(i, j);
		}
	}

	cout << kindOfColors << endl;


	return 0;

}
