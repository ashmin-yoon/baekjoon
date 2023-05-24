#include <iostream>
#include <queue>
using namespace std;
const int MAX_SIZE = 100;

int priority[MAX_SIZE];
int priority_cnt[MAX_SIZE];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}


void InitQueue(queue<int>& q) {
		while(!q.empty()) {
			q.pop();
		}
}

void InitPriorityCnt() {
	for (int i = 0; i < MAX_SIZE; i++) {
		priority_cnt[i] = 0;
	}
}

int Solution(int target, queue<int>& q) {

	int seq = 0;

	while(!q.empty()) {
		int doc = q.front();
		int pri = priority[doc];
		q.pop();

		// 우선순위 확인
		bool gotoBack = false;
		for (int i = 9; i > pri; i--) {
			if (priority_cnt[i]) {
				gotoBack = true;
				break;
			}
		}

		// 다시 삽입
		if (gotoBack) {
			q.push(doc);
			continue;
		}

		// 값 조정
		seq++;
		priority_cnt[pri]--;

		// 꺼낸 문서 확인
		if (doc == target) {
			return seq;
		}
	}

	return seq;
}

int main() {
	int T;
	int N, M;

	queue<int> q;

	cin >> T;
	while(T--) {
		InitQueue(q);
		InitPriorityCnt();

		cin >> N;
		cin >> M; // M 번째 놓여진 문서
		for (int i = 0; i < N; i++) {
			cin >> priority[i];
			priority_cnt[priority[i]]++;
			q.push(i);
		}

		cout << Solution(M, q) << "\n";
	}


	return 0;
}
