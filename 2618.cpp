#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

// 풀지못하여 여러 해설지 보았음
// https://injae-kim.github.io/problem_solving/2020/03/11/baekjoon-2618.html

class Point {
	public:
		Point() {}
		Point(int x, int y) {
			this->x = x;
			this->y = y;
		}
		int x;
		int y;
		void SetPoint(int x, int y) {
			this->x = x;
			this->y = y;
		}
};


int dp[1001][1001];
Point incident[1001];
int N;
int W;

int GetMinDist(int P1, int P2) {
	//cout << "\nP1 = " << P1 << " P2 = " << P2 << "호출" << endl;
	// 모든 사건 해결
	if (P1 == W || P2 == W)
		return 0;

	// 값이 있으면 해당 값 리턴
	if (dp[P1][P2] != -1)
		return dp[P1][P2];

	dp[P1][P2] = 987654321;
	
	// 다음 사건
	int next = max(P1, P2) + 1;

	// 경찰 P1이 다음 사건 해결 했을 경우
	int dist_p1;
	if (P1 == 0) dist_p1 = abs(incident[next].x - 1) + abs(incident[next].y - 1);
	else dist_p1 = abs(incident[next].x - incident[P1].x) + abs(incident[next].y - incident[P1].y);
	//cout << "P1 = " << P1 << " Next = " << next << "\t" << dist_p1 << endl;

	// 경찰 P2가 다음 사건 해결했을 경우
	int dist_p2;
	if (P2 == 0) dist_p2 = abs(incident[next].x - N) + abs(incident[next].y - N);
	else dist_p2 = abs(incident[next].x - incident[P2].x) + abs(incident[next].y - incident[P2].y);

	//cout << "Next = " << next << " P2 = " << P2 << "\t" << dist_p2 << endl;

	// 재귀적 계산
	int value1 = GetMinDist(next, P2) + dist_p1;
	int value2 = GetMinDist(P1, next) + dist_p2;

	// 채워 나가는 방식이 아니라
	// 뒷쪽 인덱스를 채우고 되돌아가면서 이전 값들에 중복해서 저장됨
	return dp[P1][P2] = min(value1, value2);

}

void TraceRoute(int P1, int P2) {
	if (P1 == W || P2 == W)
		return;

	int next = max(P1, P2) + 1;

	// 경찰 P1이 다음 사건 해결 했을 경우
	int dist_p1;
	if (P1 == 0) dist_p1 = abs(incident[next].x - 1) + abs(incident[next].y - 1);
	else dist_p1 = abs(incident[next].x - incident[P1].x) + abs(incident[next].y - incident[P1].y);
	//cout << "P1 = " << P1 << " Next = " << next << "\t" << dist_p1 << endl;

	// 경찰 P2가 다음 사건 해결했을 경우
	int dist_p2;
	if (P2 == 0) dist_p2 = abs(incident[next].x - N) + abs(incident[next].y - N);
	else dist_p2 = abs(incident[next].x - incident[P2].x) + abs(incident[next].y - incident[P2].y);

	// 재귀적 계산
	int value1 = GetMinDist(next, P2) + dist_p1;
	int value2 = GetMinDist(P1, next) + dist_p2;

	// P1이 해결
	if (value1 < value2)
	{
		cout << 1 << endl;
		TraceRoute(next, P2);
	}
	else // P2 해결
	{
		cout << 2 << endl;	
		TraceRoute(P1, next);
	}


}

int main() {
	cin >> N;
	cin >> W;

	memset(dp, -1, sizeof(dp)); // -1로 초기화

	for (int i = 1; i <= W; i++) {
		cin >> incident[i].x >> incident[i].y;
	}

	cout << GetMinDist(0, 0) << endl;
	TraceRoute(0, 0);


	return 0;
}
