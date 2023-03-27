#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 10;
const int INF = 987654321;

int W[MAX][MAX];
int N;
bool visited[MAX];
int start = 0;

int Solution(int picked, int count, int weightSum) {
	if (count == N) {
		return weightSum;
	}

	int result = INF;

	// 마지막 도시 방문 -> 원래 자리로(0)
	if (count == N - 1 && W[picked][start] != 0)
		return Solution(start, count+1, weightSum + W[picked][start]);

	// 시작 지점 0 제외
	for (int next = 1; next < N; next++) {
		if (visited[next]) continue;
		int nextWeight = W[picked][next];
		if (nextWeight == 0) continue;
		
		visited[next] = true;
		result = min(result, Solution(next, count + 1, weightSum + nextWeight));
		visited[next] = false;
	}
	return result;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	int ans = Solution(0, 0, 0);
	cout << ans;
	return 0;
}
