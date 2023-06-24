#include <iostream>
using namespace std;
const int MAX_SIZE = 101;
const int INF = 987654321;

int N, M;
int ans = 0;
int SumValue = INF;
int dist[MAX_SIZE][MAX_SIZE];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> M;
	int p1, p2;
	for (int i = 0; i < M; i++) {
		cin >> p1 >> p2;
		dist[p1][p2] = dist[p2][p1] = 1;
	}
}

void Init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			dist[i][j] = INF; // 전체
		}
		dist[i][i] = 0; // 자기 자신
	}
}

void Solution() {
	// floyd-warshall
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				// 경로 없음
				if (dist[i][k] == INF || dist[k][j] == INF) continue;
				// 경로 있음
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j] + 1);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == INF) continue;
			sum += dist[i][j];
			// 미리 중단
			if (sum > SumValue)
				break;
		}

		// 갱신
		if (SumValue > sum) {
			ans = i;
			SumValue = sum;
		}
	}
}

int main() {
	Init();
	FastIO();
	Input();
	Solution();

	cout << ans;
	return 0;
}
