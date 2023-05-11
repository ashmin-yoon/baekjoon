#include <iostream>
using namespace std;
const int MAX_SIZE = 101;
const int INIT = -1;
const int OOR = -2;

// 더할 때 unsigned long long += int 주의

int arr[MAX_SIZE];
unsigned long long value_cnt[MAX_SIZE][21]; // [idx1]번째 [idx2] 값 개수
int N;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

bool OutOfRange(int value) {
	if (value < 0 || value > 20)
		return true;
	return false;
}


unsigned long long Solution() {
	
	// 첫번째 값
	value_cnt[1][arr[1]] = 1;

	for (int i = 2; i < N; i++) {
		for (int j = 0; j <= 20; j++) {
			// 이전 단계 값 개수
			unsigned long long pre_cnt = value_cnt[i - 1][j]; 
			if (pre_cnt == 0)
				continue;

			// 이전 값 = j
			// 현재값 = arr[i]

			int p_value = j + arr[i];
			int m_value = j - arr[i];

			// +
			if (!OutOfRange(p_value)) {
				value_cnt[i][p_value] += pre_cnt;
			}

			// -
			if (!OutOfRange(m_value)) {
				value_cnt[i][m_value] += pre_cnt;
			}
		}
	}

	int last_value = arr[N];
	return value_cnt[N-1][last_value];
}

int main() {
	FastIO();
	Input();
	cout << Solution();


	return 0;
}
