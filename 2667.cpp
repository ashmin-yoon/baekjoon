#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_SIZE = 25;

int N;

bool map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int DFS(int y, int x)
{
	int rev = 0;
	vector<pair<int, int> > s;
	s.push_back(make_pair(y, x));

	pair<int, int> curr;
	while(!s.empty())
	{
		curr = s.back();
		s.pop_back();
		bool& currVisited = visited[curr.first][curr.second];
		if (currVisited)
			continue;
		currVisited = true;
		rev++;

		for (int i = 0; i < 4; i++)
		{
			int nextY = curr.first + dy[i];
			int nextX = curr.second + dx[i];
			if (nextX < 0 || nextY < 0) continue;
			if (nextX >= N || nextY >= N) continue;
			if (map[nextY][nextX])
			{
				s.push_back(make_pair(nextY, nextX));
			}
		}
	}
	return rev;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			map[i][j] = str[j] == '1';
		}
	}



	int groupCount = 0;
	int partialCount = 0;
	vector<int> ans;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!map[i][j] || visited[i][j]) 
				continue;
			groupCount++;
			ans.push_back(DFS(i, j));
		}
	}

	sort(ans.begin(), ans.end());

	cout << groupCount << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}
