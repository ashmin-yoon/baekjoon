#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 1001;
const int INF = 987654321;

int S;
bool visited[MAX_SIZE][MAX_SIZE];

// 해당 문제는 다른 사람 답 보고 공부
// 2023-02-15

typedef struct Data{
	Data(int display, int clipboard, int cost) {
		this->display = display;
		this->clipboard = clipboard;
		this->cost = cost;
	}
	int display;
	int clipboard;
	int cost;
} Data;

int main() {
	cin >> S;

	queue<Data> q;
	q.push(Data(1, 0, 0));

	while(!q.empty())
	{
		int display = q.front().display;
		int clipboard = q.front().clipboard;
		int cost = q.front().cost;
		//printf("display = %d, clip = %d, cost = %d\n", display, clipboard, cost);
		q.pop();

		if (display == S) 
		{
			cout << cost << "\n";
			break;
		}

		if (0 < display && display < MAX_SIZE) 
		{
			// 복사 - 클립보드 채우기
			if (!visited[display][display])
			{
				visited[display][display] = true;
				q.push(Data(display, display, cost+1));
			}

			// 화면의 이모티콘 삭제
			if (!visited[display - 1][clipboard])
			{
				visited[display - 1][clipboard] = true;
				q.push(Data(display - 1, clipboard, cost+1));
			}
		}

		if (clipboard > 0 && display + clipboard < MAX_SIZE)
		{
			// 붙여넣기
			if (!visited[display + clipboard][clipboard])
			{
				visited[display + clipboard][clipboard] = true;
				q.push(Data(display + clipboard, clipboard, cost + 1));
			}
		}
	}

	return 0;
}
