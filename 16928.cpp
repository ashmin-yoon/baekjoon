#include <iostream>
#include <queue>
using namespace std;
const int MAX_SIZE = 101;

int board[MAX_SIZE];
int visited[MAX_SIZE];

int N, M;
queue<pair<int, int> > q;

void Init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		board[i] = i;
	}
}

void BFS(int start) {

	q.push(make_pair(start, 0));

		
	while(!q.empty())
	{
		int curr 	= q.front().first;
		int cnt		= q.front().second;
		q.pop();
		//cout << curr << "번째 칸 " << cnt << "번 만에 방문" << endl;

		for (int i = 1; i <= 6; i++)
		{
			int next = board[curr + i];
			if (visited[next]) continue;
			q.push(make_pair(next, cnt + 1));
			visited[next] = cnt + 1;
		}
	}


}

int main()
{

	Init();
	cin >> N >> M;


	int x, y;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		board[x] = y;
	}

	int u, v;
	for (int j = 0; j < M; j++)
	{
		cin >> u >> v;
		board[u] = v;
	}


	BFS(1);

	cout << visited[100];


	return 0;
}
