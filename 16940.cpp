#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 100001;

vector<int> adj[MAX_SIZE];
vector<int> path;

vector<int> candidate[MAX_SIZE];
bool visited[MAX_SIZE];

int N;


void Input() {
	cin >> N;

	// 간선
	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//
	int vertex;
	for (int i = 0; i < N; i++)
	{
		cin >> vertex;
		path.push_back(vertex);
	}

}



int GetAvailableCount(int vertex) {

	int count = 0;

	for (int i = 0; i < adj[vertex].size(); i++)
	{
		int next = adj[vertex][i];
		if (visited[next]) continue;
		count++;
	}

	return count;
}

bool BFS() 
{


	queue<int> trace;
	trace.push(path[0]);
	int path_index = 1;
	visited[path[0]] = true;

	while(!trace.empty())
	{
		int vertex = trace.front();
		trace.pop();
		int available_count = GetAvailableCount(vertex);  // 이동 가능 경로 수

		//cout << vertex << "  " << available_count << endl;

		// 이동 가능한 개수 만큼 path 에서 꺼내옴
		for (int i = 0; i < available_count; i++)
		{
			visited[path[path_index + i]] =  true;
			trace.push(path[path_index + i]);
			//cout << path[path_index + i] << endl;
		}

		path_index += available_count;


		// 이동 가능 경로가 존재한다면 잘못됨
		if (GetAvailableCount(vertex))
		{
			//cout << vertex << "잘못됨 \n";
			return false;
		}
	}

	return true;

}



int main()
{

	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();


	// 시작 정점은 1이다. 고정
	if (path[0] != 1)
	{
		cout << false << endl;
		return -1;
	}

	if (BFS()) cout << true << endl;
	else cout << false << endl;



	return 0;
}
