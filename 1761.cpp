#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#define MAX_K 17
#define MAX_SIZE 40001
using namespace std;

int N, M;
int MAX_LEVEL;
int K;
pair<int, int> parent[MAX_SIZE][MAX_K]; // parent, dist
vector<pair<int, int> > adj[MAX_SIZE]; // vertex, dist
int level[MAX_SIZE];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Init() {
	// 모든 부모 초기화
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_K; j++) {
			parent[i][j].first = -1;
			parent[i][j].second = -1;
			level[i] = -1;
		}
	}
}

void Input() {
	cin >> N;
	int u, v, d;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> d;
		adj[u].emplace_back(v, d);
		adj[v].emplace_back(u, d);
	}
}

void Bfs(int start) {
	bool visited[MAX_SIZE];
	memset(visited, false, sizeof(visited));

	queue<int> q;
	q.push(start);
	visited[start] = true;	
	parent[start][0].first = start;
	parent[start][0].second = 0;
	MAX_LEVEL = 0;
	level[start] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (pair<int, int> next : adj[v]) {
			int _v = next.first;
			int _d = next.second;

			if (visited[_v])
				continue;

			// 바로 윗 칸 부모 설정
			parent[_v][0].first = v;
			parent[_v][0].second = _d;
			level[_v] = level[v] + 1;
			MAX_LEVEL = level[_v];
			visited[_v] = true;
			q.push(_v);
		}
	}
}


// least common ancestor
int LCA(int n1, int n2, int& dist) {

	if (level[n1] > level[n2]) {
		int tmp = n1;
		n1 = n2;
		n2 = tmp;
	}

	dist = 0;

	// n1이 n2 보다 위 or 같음
	if (level[n1] != level[n2]) {
		for (int i = K; i >= 0; i--) {
			if (level[parent[n2][i].first] < level[n1])
				continue;
			dist += parent[n2][i].second;
			n2 = parent[n2][i].first;
		}
	}

	// 정점이 같지 않음
	if (n1 != n2) {
		for (int i = K; i >= 0; i--) {
			if (parent[n1][i].first != parent[n2][i].first) {
				dist += parent[n1][i].second;
				dist += parent[n2][i].second;

				n1 = parent[n1][i].first;
				n2 = parent[n2][i].first;
			}
		}

		dist += parent[n1][0].second;
		dist += parent[n2][0].second;
		return parent[n1][0].first;
	}

	// 정점 같음
	return n1;
}

void SetAncestor() {
	K = 0;
	for (int i = 1; i < MAX_LEVEL; i *= 2) {
		K++;
	}

	for (int j = 1; j <= K; j++) {
		for (int i = 1; i <= N; i++) {
			parent[i][j].first = parent[parent[i][j - 1].first][j - 1].first;
			parent[i][j].second = parent[i][j - 1].second + parent[parent[i][j - 1].first][j - 1].second;
		}
	}
}

void Solution() {
	// 시작 정점 1로 Bfs 구하기(부모 설정)
	Bfs(1);
	SetAncestor();

	cin >> M;
	int u, v, dist;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		LCA(u, v, dist);
		printf("%d\n", dist);
	}
}

int main() {
	FastIO();
	Init();
	Input();
	Solution();	
}
