#include <iostream>
using namespace std;
const int MAX_SIZE = 100001;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

class MaxHeap {
	public:
		int size;
		int arr[MAX_SIZE];
		MaxHeap() {
			size = 0;
		}

		void push(int data) {
			if (size == 0) {
				arr[1] = data;
				size++;
				return;
			}

			int idx = size + 1;
			arr[idx] = data;
			size++;

			int parent = idx / 2;
			while(parent > 0 && arr[parent] < arr[idx]) {
				swap(arr[idx], arr[parent]);
				idx = parent;
				parent = idx / 2;
			}
		}

		int pop() {
			if (size == 0) {
				return 0;
			}

			int ret = arr[1];
			arr[1] = arr[size];

			int idx = 1;
			int child = idx * 2;
			while (child < size) {
				// 자식 비교(더 큰 자식 고름)
				if (child + 1 < size && arr[child] < arr[child + 1]) {
					child++;
				}

				if (arr[idx] >= arr[child]) {
					break;
				}

				swap(arr[idx], arr[child]);
				idx = child;
				child = idx * 2;
			}

			size--;
			return ret;
		}

		void print() {
			for (int i = 0; i < size; i++) {
				cout << arr[i] << " ";
			}
			cout << "\n";
		}

	private:
		void swap(int& a, int& b) {
			int t = a;
			a = b;
			b = t;
		}

};


int main() {
	FastIO();

	int N;
	cin >> N;

	int value;
	MaxHeap mh;

	for (int i = 0; i < N; i++) {
		cin >> value;
		if (value == 0) {
			cout << mh.pop() << "\n";
		}
		else {
			mh.push(value);
		}
	}

}
