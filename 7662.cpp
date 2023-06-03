#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
const int MAX_SIZE = 1000000;

int T;
int K;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

// 방향 주의
struct MaxCmp{
	bool operator()(int a, int b) {
		return a < b;
	}
};

struct MinCmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

class DoublePriorityQueue {
	public:
		priority_queue<int, vector<int>, MaxCmp> maxPQ;
		priority_queue<int, vector<int>, MinCmp> minPQ;
		map<int, int> m; // 해당 값의 개수 저장
		map<int, int>::iterator it;

		void Clear() {

			while(!maxPQ.empty()) {
				maxPQ.pop();
			}

			while(!minPQ.empty()) {
				minPQ.pop();
			}

			m.clear();
		}

		void Push(int data) {

			addDataToMap(data);

			// 데이터 저장
			maxPQ.push(data);
			minPQ.push(data);
		}

		bool Empty() {
			while(!maxPQ.empty()) {
				if (isExistence(maxPQ.top()))
					break;
				maxPQ.pop();
			}

			while(!minPQ.empty()) {
				if (isExistence(minPQ.top()))
					break;
				minPQ.pop();
			}

			if (maxPQ.empty() || minPQ.empty())
				return true;
			return false;
		}

		int PeekMax() {
			int value;
			while(!Empty()) {
				value = maxPQ.top();
				if (isExistence(value))
					break;
				maxPQ.pop();
			}

			return value;
		}

		int PeekMin() {
			int value;
			while(!Empty()) {
				value = minPQ.top();
				if (isExistence(value))
					break;
				minPQ.pop();
			}
			return value;
		}

		void PopMax() {
			while(!Empty()) {
				int value = maxPQ.top();
				maxPQ.pop();

				if (isExistence(value)) {
					//cout << "PopMax : " << value << "\n";
					deleteDataToMap(value);
					break;
				}
			}
		}

		void PopMin() {
			while(!Empty()) {
				int value = minPQ.top();
				minPQ.pop();

				if (isExistence(value)) {
					//cout << "PopMin : " << value << "\n";
					deleteDataToMap(value);
					break;
				}
			}

		}

	private:
		void addDataToMap(int data) {
			// 이미 있을 때
			if ((it = m.find(data)) != m.end()) {
				it->second++;
			}
			else {
				m.insert(make_pair(data, 1)); // data 값 1개
			}
		}

		bool deleteDataToMap(int data) {
			//cout << "deleteDataToMap : data = " << data << "\n";
			// 이미 있을 때
			if ((it = m.find(data)) != m.end()) {
				it->second--;
				if (it->second <= 0) {
					m.erase(it); // 삭제
				}
				return true;
			}
			else {
				return false;
			}
		}

		bool isExistence(int data) {
			if ((it = m.find(data)) != m.end()) {
				if (it->second > 0) {
					return true;
				}
			}
			return false;
		}

};

int main() {

	FastIO();

	DoublePriorityQueue dpq;
	cin >> T;

	while(T--) {
		dpq.Clear(); // 초기화

		cin >> K;
		char cmd;
		int value;
		for (int i = 0; i < K; i++) {
			cin >> cmd >> value;
			if (cmd == 'D' && !dpq.Empty()) {
				if (value == 1) { // 최대 삭제
					dpq.PopMax();
				} else if (value == -1) { // 최소 삭제
					dpq.PopMin();
				}
			} 
			else if (cmd == 'I') { // value 추가
				dpq.Push(value);
			}
		}

		// 정답 출력
		if (dpq.Empty()) {
			cout << "EMPTY\n";
		} else {
			cout << dpq.PeekMax() << " " << dpq.PeekMin() << "\n";
		}

	}


	return 0;
}
