#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
const int MAX_SIZE = 100001;

int N;
int K;
int arr[MAX_SIZE];
int preIdx[MAX_SIZE];
int visited[MAX_SIZE];


void BFS(int start)
{
	queue<pair<int, int> > q;
	q.push(make_pair(start, 0));
	preIdx[start] = -1;

	int idx;
	int count;
	while(!q.empty())
	{
		idx = q.front().first;
		count = q.front().second;
		q.pop();

		visited[idx] = true;
		arr[idx] = count;

		if (idx == K) break;

		int nextIdx = idx * 2;
		if (0 <= nextIdx && nextIdx < MAX_SIZE)
		{
			if (!visited[nextIdx])
			{
				q.push(make_pair(nextIdx, count + 1));
				preIdx[nextIdx] = idx;
				visited[nextIdx] = true;
			}
		}

		nextIdx = idx + 1;
		if (0 <= nextIdx && nextIdx < MAX_SIZE)
		{
			if (!visited[nextIdx])
			{
				q.push(make_pair(nextIdx, count + 1));
				preIdx[nextIdx] = idx;
				visited[nextIdx] = true;
			}
		}

		nextIdx = idx - 1;
		if (0 <= nextIdx && nextIdx < MAX_SIZE)
		{
			if (!visited[nextIdx])
			{
				q.push(make_pair(nextIdx, count + 1));
				preIdx[nextIdx] = idx;
				visited[nextIdx] = true;
			}
		}

	}
}

int main()
{
	cin >> N >> K;
	BFS(N);

	cout << arr[K] << "\n";
	vector<int> v;
	int pre = K;

	while(pre != -1)
	{
		v.push_back(pre);
		pre = preIdx[pre];
	}

	for (vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); rit++)
	{
		cout << *rit << " ";
	}
	
	return 0;
}
