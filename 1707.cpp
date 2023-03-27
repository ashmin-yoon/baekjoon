#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX_SIZE = 20001;

int T;
int N;
int M;
vector<int> vertex[MAX_SIZE];
bool visited[MAX_SIZE];
int group[MAX_SIZE];

bool verifyBipartiteGraph(int start)
{
	queue<int> q;
	q.push(start);
	group[start] = 1;

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		if (visited[curr]) continue;
		visited[curr] = true;

		for (int i = 0; i < vertex[curr].size(); i++)
		{
			int v = vertex[curr][i];
			if (group[curr] == group[v]) 
				return false;
			if (group[v] == 0)
				group[v] = group[curr] == 1 ? 2 : 1;
			if (visited[v]) continue;
			q.push(v);
		}
	}

	return true;	
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> T;

	while(T--)
	{
		cin >> N >> M;
		for (int i = 0; i <= N; i++)
		{
			vertex[i].clear();
			visited[i] = false;
			group[i] = 0;
		}

		int u, v;
		for (int i = 0; i < M; i++)
		{
			cin >> u >> v;
			vertex[u].push_back(v);
			vertex[v].push_back(u);
		}

		bool ans = true;
		for (int i = 1; i <= N; i++)
		{
			if (visited[i]) continue;
			if(verifyBipartiteGraph(i) == false)
			{
				ans = false;
				break;
			}
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
