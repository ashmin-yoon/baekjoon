#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 2000;

int N;
int M; 
int ans;
bool visited[MAX_SIZE];
vector<int> vec[MAX_SIZE];

void Solution(int target, int count)
{
	if (count == 4)
	{
		ans = 1;
		return;
	}

	visited[target] = true;

	for (int i = 0; i < vec[target].size(); i++)
	{
		int next = vec[target][i];
		if (visited[next]) continue;
		Solution(next, count + 1);
	}
	visited[target] = false;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	int f1, f2;
	for (int i = 0; i < M; i++)
	{
		cin >> f1 >> f2;
		vec[f1].push_back(f2);
		vec[f2].push_back(f1);
	}

	for (int i = 0; i < N; i++)
	{
		Solution(i, 0);
		if (ans)
			break;
	}
		
	cout << ans;


	return 0;
}
