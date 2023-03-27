#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_SIZE = 3001;

vector<int> graph[MAX_SIZE];
bool visited[MAX_SIZE];
bool cycle[MAX_SIZE];
int dist[MAX_SIZE];

int N;


void Cycle(vector<int>& path, int end)
{
	//cout << "cycle " << path.back() << " ~ end = " << end << endl;

	// 최근 경로 ~ 순환 지점까지
	for (int j = path.size() - 1; j >= 0; j--)
	{
		cycle[path[j]] = true;
		if (path[j] == end)
			break;	
	}

}

void DFS(int vertex, int pre_vertex, vector<int>& path)
{
	if (visited[vertex]) return;
	visited[vertex] = true;
	path.push_back(vertex); // 경로 추가

	for (int i = 0; i <	graph[vertex].size(); i++)
	{
		int next = graph[vertex][i];

		if (next == pre_vertex) continue;
		if (visited[next]) // 수환 존재
		{
			if (!cycle[vertex]) 	// 현재가 사이클이 아닐 때
				Cycle(path, next); // 순환 처리
			continue;
		}
		DFS(next, vertex, path);
	}

	path.pop_back(); // 경로 삭제
}



void InitVisited() {

	for (int i = 0; i <= N; i++)
	{
		visited[i] = false;
	}
}



void BFS(int vertex) {

	// 중간 연결 or 끝은 X
	if (graph[vertex].size() < 3) return;
	if (visited[vertex]) return;
	if (!cycle[vertex]) return; // Not Cycle

	queue<int> q;
	queue<int> count_q;

	q.push(vertex);
	count_q.push(0);

	while(!q.empty())
	{
		int v = q.front();
		int cnt = count_q.front();
		q.pop();
		count_q.pop();

		if (visited[v]) continue;
		visited[v] = true;

		// 길이 최소화

		if (dist[v] == 0)
			dist[v] = cnt;
		else 
			dist[v] = min(dist[v], cnt);


		for (int i = 0; i < graph[v].size(); i++)
		{
			int next = graph[v][i];
			if (cycle[next]) continue;
			if (visited[next]) continue;
			q.push(next);
			count_q.push(cnt + 1);
		}
	}

}



int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	
	// 순환 찾기
	InitVisited();
	for (int i = 1; i <= N; i++)
	{
		vector<int> path;
		DFS(i, 0, path);
	}

	
	// 거리 찾기
	InitVisited();
	for (int i = 1; i <= N; i++)
	{
		BFS(i);
	}

	// 정답 출력
	for (int i = 1; i <= N; i++)
	{
		cout << dist[i] << " ";
	}


	return 0;
}
