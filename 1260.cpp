#include <iostream>
#include <cstring> // memset
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 1001;

int N;
int M;
int S;

vector<int> v[MAX_SIZE];
bool visited[MAX_SIZE];

// Depth First Search
void DFS(int start)
{
	if (visited[start]) return;

	vector<int> dfs_v;
	dfs_v.push_back(start);
	int curr;
	while(!dfs_v.empty())
	{
		curr = dfs_v.back();
		dfs_v.pop_back();
		if (visited[curr]) continue;
		visited[curr] = true;
		cout << curr << " ";
		
		vector<int>::reverse_iterator rit;
		// 내림 순 접근(현재 오름차순 정렬 상태)
		for (rit = v[curr].rbegin(); rit != v[curr].rend(); rit++)
		{
			int next = *rit;
			if (visited[next]) continue;
			dfs_v.push_back(next);
		}
	}
}

// Breath First Search
void BFS(int start)
{
	queue<int> q;
	if (visited[start]) return;

	q.push(start);

	int curr;
	while(!q.empty())
	{
		curr = q.front();
		q.pop();
		if (visited[curr]) continue;
		visited[curr] = true;
		cout << curr << " ";

		for (auto x : v[curr])
		{
			if (visited[x]) continue;
			q.push(x);
		}
	}

}

void Init()
{
	memset(visited, false, sizeof(bool) * MAX_SIZE);
}

int main() 
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M >> S;
	for (int i = 0; i < M; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}

	for (int i = 0; i < MAX_SIZE; i++)
		sort(v[i].begin(), v[i].end());

	Init();
	DFS(S);
	cout << "\n";

	Init();
	BFS(S);
	cout << "\n";
}
