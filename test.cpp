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

//neighbor

// 현재칸 기준 - 좌상, 우상, 좌,  우, 좌하단, 우하단
int dy[6] = {-1, -1, 0, 0, 1, 1};
int dx[6] = {0, 1, -1, 1, -1, 0};

// DFS 버전 통과 후
// 기존 BFS 코드 수정
// 주변 색상 확인 - OutOfRange 추가

bool OutOfRange(int y, int x)
{
	if (y < 0 || y >= N) return true;
	if (x < 0 || x >= N) return true;

	return false;
}



void BFS(int start_y, int start_x)
{
	visited[start_y][start_x] = true;
	if (kindOfColors >= 3) 
	{
		kindOfColors = 3;
		return;
	}
    
	queue<pair<int, int> > q;
	q.push(make_pair(start_y, start_x));

	while(!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();


		// 가능한 색상 확인
		// 반례로 인해 높은 번호 ~ 아래로 시도
		for (int c = kindOfColors; c >= 0; c--)
		{
			bool isAvailableColor = true;
			for (int i = 0; i < 6; i++)
			{
				int neighbor_y = y + dy[i];
				int neighbor_x = x + dx[i];
				if (OutOfRange(neighbor_y, neighbor_x)) continue;
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

		// 칠해야 할 칸 확인
		for (int i = 0; i < 6; i++)
		{
			int next_y = y + dy[i];
			int next_x = x + dx[i];


			if (OutOfRange(next_y, next_x)) continue;
			if (!isColor[next_y][next_x]) continue;
			if (visited[next_y][next_x]) continue; 		// 방문 여부

			visited[next_y][next_x] = true;
			q.push(make_pair(next_y, next_x));
		}

	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char c;
		for (int j = 0; j < N; j++)
		{
			cin >> c;
			if (c == 'X') isColor[i][j] = true;
			else isColor[i][j] = false;
		}
	}


	// 그냥 진행
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (isColor[i][j] && !visited[i][j])
				BFS(i, j);
		}
	}

	cout << kindOfColors << endl;


	// 그냥 진행
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << colorNumber[i][j];
		}
		cout << endl;
	}

	return 0;
}
