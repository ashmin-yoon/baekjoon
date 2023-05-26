#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 100000;

int N;
int goal[MAX_SIZE];
int arr[MAX_SIZE];
vector<int> v;
vector<char> ans;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		goal[i] = arr[i];
	}
}

bool Solution() {

	v.push_back(arr[0]);
	ans.push_back('+');

	int goal_idx = 0;
	int idx = 1;

	while(idx < N) {
		int top = v.back();

		// 목표하는 값 같으면 꺼내기
		if (top == goal[goal_idx]) {
			goal_idx++;
			v.pop_back();
			ans.push_back('-');
			continue;
		}

		// 다르면 push
		v.push_back(arr[idx]);
		idx++;
		ans.push_back('+');
	}

	// 스택에 남은 내용 배출
	while(v.size()) {
		int top = v.back();
		v.pop_back();

		if (top == goal[goal_idx]) {
			goal_idx++;
			ans.push_back('-');
		}
		else { // 다름
			return false;
		}
	}

	return true;
}

int main() {
	FastIO();
	Input();
	sort(arr, arr + N);

	if (Solution()) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}
	else {
		cout << "NO";
	}

	return 0;
}
