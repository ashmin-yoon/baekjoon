// 다른 사람 정답 코드 https://hagisilecoding.tistory.com/20
#include <iostream>
#include <queue>

using namespace std;

const int MAX_SIZE = 100001;
int n;	// 수빈이
int k;	// 동생

bool visit[MAX_SIZE];

void bfs(int idx) {
	queue<pair<int, int> > q;	// (인덱스, 횟수)
	q.push(make_pair(idx, 0));

	while(!q.empty()) {
		int x = q.front().first; // 인덱스
		int count = q.front().second;
		q.pop();

		// 동생 위치
		if (x == k) {
			cout << count;
			break;
		}

		// 각 다음 좌표 q에 넣어준다.
		if (x+1 >= 0 && x+1 < MAX_SIZE) {
			if (!visit[x+1]) {
				visit[x+1] = true;
				q.push(make_pair(x+1, count+1));
			}
		}

		if (x-1 >= 0 && x-1 < MAX_SIZE) {
			if (!visit[x-1]) {
				visit[x-1] = true;
				q.push(make_pair(x-1, count+1));
			}
		}

		if (2*x >= 0 && 2*x < MAX_SIZE) {
			if (!visit[2*x]) {
				visit[2*x] = true;
				q.push(make_pair(2*x, count+1));
			}
		}

	}
}

int main() {
	cin >> n >> k;
	visit[n] = true;
	bfs(n);	// 수빈이 위치에서 시작
	return 0;
}
