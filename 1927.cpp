#include <iostream>
using namespace std;
const int MAX_SIZE = 100000;

// 확실히 1번 인덱스부터 사용하는게 편할 듯 하다.

class MinimumHeap {
	private:
		int size;
		int arr[MAX_SIZE];
		void swap(int& a, int& b) {
			int t = a;
			a = b;
			b = t;
		}
	public:
		MinimumHeap() {
			size = 0;
		}
		void PrintArr() {
			for (int i = 0; i < size; i++) {
				cout << arr[i] << " ";
			}
			cout << "\n";
		}

		void Push(int num) {
			int idx = size;
			int parent = (idx - 1) / 2;

			arr[idx] = num; // 마지막 삽입
			size++;

			// 적절한 위치로 이동
			while (arr[parent] > arr[idx]) {
				swap(arr[parent], arr[idx]);
				idx = parent;
				parent = (idx - 1) / 2;
			}

		}

		int Pop() {
			if (size == 0) {
				return 0;
			}

			int ret = arr[0];
			int idx = 0;
			arr[idx] = arr[size - 1]; // 마지막을 위로[0] 올림
			size--;

			int child = idx * 2 + 1;

			while (child < size) {
				// 자식 중 더 작은 값 찾기
				if (child - 1 < size && arr[child] > arr[child + 1] ) {
					child++;
				}

				// 종료 조건
				if (arr[idx] < arr[child])
					break;

				swap(arr[idx], arr[child]);
				idx = child;
				child = idx * 2 + 1; // left child
			}

			return ret;
		}
};

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

int main() {
	FastIO();

	int N;
	cin >> N;

	MinimumHeap minHeap;
	int value;
	for (int i = 0; i < N; i++) {
		cin >> value;
		if (value > 0) {
			minHeap.Push(value);
		} else {
			cout << minHeap.Pop() << "\n";
		}
	}

	return 0;
}	
