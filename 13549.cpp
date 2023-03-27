#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX_SIZE = 100001;

int N;
int K;
bool visited[MAX_SIZE];

struct cmp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		if (p1.second != p2.second)
			return p1.second > p2.second;

		// .second equal
		return false;
	}
};

typedef pair<int, int> pair_ii;

int main() {
	cin >> N >> K;

	priority_queue<pair_ii, vector<pair_ii>, cmp> pq;
	pq.push(make_pair(N, 0));
	// visited[N] = true;

	while(!pq.empty())
	{
		int idx = pq.top().first;
		int count = pq.top().second;
		pq.pop();

		if (visited[idx]) continue;
		visited[idx] = true;

		if (idx == K)
		{
			cout << count << "\n";
			break;
		}

		
		// x - 1
		if (0 <= idx-1 && !visited[idx-1])
		{
			//visited[idx-1] = true;
			pq.push(make_pair(idx-1, count+1));
		}

		// x + 1
		if (idx+1 < MAX_SIZE && !visited[idx+1])
		{
			// visited[idx+1] = true;
			pq.push(make_pair(idx+1, count+1));
		}

		// 2 x
		if (idx*2 < MAX_SIZE && !visited[idx*2])
		{
			// visited[idx*2] = true;
			pq.push(make_pair(idx*2, count));
		}
	}

	return 0;
}
