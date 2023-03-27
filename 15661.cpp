#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 20;

int N;
int S[MAX][MAX];
int rowSum[MAX];
int columnSum[MAX];
int total = 0;
int ans = 987654321;

void dfs(int pick, int count, int teamStateDiff) {
	teamStateDiff = abs(teamStateDiff);
	// 1 ~ N/2명 선택 = N-1명 선택 ~ N/2 명 선택

	ans = min(ans, teamStateDiff);

	if (count == N/2) {
		return;
	}

	for (int i = pick; i < N - 1; i++) {
		dfs(i + 1, count + 1, teamStateDiff - rowSum[i] - columnSum[i]);
	}

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
			rowSum[i] 	+= S[i][j];
			columnSum[j]+= S[i][j];
			total 			+= S[i][j];
		}
	}

	dfs(0, 0, total);
	cout << ans << endl;

	return 0;
}
