#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

// 우선 순위 기준
// 절대 값ㅇ ㅣ가장 작은 것이 앞에
// 절대 값이 같다면 음수가 먼저
struct CmpPriority {

	// 일반 sort와 기준이 다름
	// true 면 바뀜
	bool operator()(int &a, int &b) {
		if (abs(a) == abs(b)) {
			return a > b; // a 양수 b 음수
		}

		return abs(a) > abs(b);
	}
};

class AbsoluteValueHeap {
	public:
		priority_queue<int, vector<int>, CmpPriority> pq;

		void Push(int data) {
			pq.push(data);
		}

		int Pop() {
			if (pq.empty()) {
				return 0;
			}

			int ret = pq.top();
			pq.pop();
			return ret;
		}
};

int main() {
	FastIO();
	int value;
	AbsoluteValueHeap avh;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> value;

		// pop
		if (value == 0) {
			cout << avh.Pop() << "\n";
		}
		// push
		else {
			avh.Push(value);
		}
	}

	return 0;
}
