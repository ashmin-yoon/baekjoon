#include <iostream>
#include <queue>
using namespace std;

const int MAX_SIZE = 101;

int N, M;
bool adj[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N;
	cin >> M;

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		adj[u][v] = adj[v][u] = true;
	}
}

void Solution() {

	queue<int> q;
	q.push(1);
	visited[1] = true;
	int cnt = 0;

	while(!q.empty()) {

		int curr = q.front();
		q.pop();

		for (int i = 2; i <= N; i++) {
			if (adj[curr][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
				cnt++;
			}
		}
	}

	cout << cnt;
}

int main() {
	FastIO();
	Input();
	Solution();


	return 0;
}
