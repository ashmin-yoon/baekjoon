#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 1000000;

int N, M;
int tree[MAX_SIZE];
int maxHeight = -1;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
		maxHeight = max(maxHeight, tree[i]);
	}
}

bool IsPossible(int height) {
	int neededTree = M;
	for (int i = 0; i < N; i++) {
		if (tree[i] > height) {
			neededTree -= (tree[i] - height);
			// for 끝나고 검사하면 오버플로(음수 --> 양수) 발생
			// 타입을 long long 변경하거나 지금처럼 내부에서 검사 후 return
			if (neededTree <= 0)
				return true;
		}
	}
	return false;
}

void Solution() {
	int height = -1;

	int left = 0;
	int right = maxHeight;
	int mid = (left + right) / 2;

	while(left <= right) {
		mid = (left + right) / 2;
		bool isPossible = IsPossible(mid);

		// 가능
		if (isPossible) {
			left = mid + 1;
			height = mid;
		}
		else {
			right = mid - 1;
		}

	}

	cout << height;
}

int main() {
	FastIO();
	Input();
	Solution();

	return 0;
}
