#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 300;
const int INF = 987654321;

int T;
int N;
int map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

typedef struct {
	int y;
	int x;
} Point;

bool OutOfRange(Point& p)
{
	if (p.y < 0 || p.y >= N) return true;
	if (p.x < 0 || p.x >= N) return true;
	return false;
}

void BFS(Point p) 
{
	queue<Point> q;
	queue<int> countQueue;
	q.push(p);
	countQueue.push(0);

	Point curr;
	Point next;

	while(!q.empty())
	{
		curr = q.front();
		q.pop();

		int count = countQueue.front();
		countQueue.pop();

		if (visited[curr.y][curr.x]) continue;
		visited[curr.y][curr.x] = true;
		map[curr.y][curr.x] = count;

		for (int i = 0; i < 8; i++)
		{
			next = curr;
			next.y += dy[i];
			next.x += dx[i];

			if(OutOfRange(next)) continue;
			if(visited[next.y][next.x]) continue;
			q.push(next);
			countQueue.push(count + 1);
		}
	}
}

int main() 
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> T;
	Point start;
	Point end;

	while(T--)
	{
		cin >> N;
		cin >> y >> x;
		cin >> end.y >> end.x;
		memset(visited, 0, sizeof(visited));
		memset(map, -1, sizeof(map));
		BFS(start);
		// end point 확인
		cout << map[end.y][end.x] << "\n";
	}

	return 0;
}

