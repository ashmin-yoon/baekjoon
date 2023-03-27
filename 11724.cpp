#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAX_SIZE = 1001;

int N;
int M;
int ans;
bool visited[MAX_SIZE];
vector<int> v[MAX_SIZE];

void DFS(int start)
{
	
	vector<int> s;
	s.push_back(start); //stack

	while(!s.empty())
	{
		int curr = s.back();
		s.pop_back();

		if(visited[curr]) 
			continue;

		visited[curr] = true;
		for (int i = 0; i < v[curr].size(); i++)
		{
			if(v[curr][i]) 
				continue;
			s.push_back(v[curr][i]);
		}
	}
}

int main() 
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int v1, v2;
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}

	for (int i = 1; i <= N; i++)
	{
		if(visited[i])
			continue;
		ans++;
		DFS(i);
	}

	cout << ans;
	return 0;
}
