#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 10000;

int K, N;

int line[MAX_SIZE];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> line[i];
	}
}

bool desc(int a, int b) {
	return a > b;
}

// length 로 만들 수 있는 개수(N이상이면 N에서 멈춤)
int GetLineCount(int length) {
	int cnt = 0;

	for (int i = 0; i < K; i++) {
		if ((line[i] / length) == 0)
			break;
		cnt += (line[i] / length);
	}

	return cnt;
}

int main() {
	FastIO();
	Input();

	sort(line, line + K, desc); // 내림차순

	long long left = 1;
	long long right = line[0]; // 최대 길이 랜선
	long long ans = 0;

	while(left <= right) {
		long long mid = (left + right) / 2;
		int cnt = GetLineCount(mid);
		//cout << mid << endl;

		// 많이 얻을 수 있음 == length 짧음
		if (cnt >= N) {
			left = mid + 1;
			ans = max(ans, mid);
		}
		else { // 부족함 == 길이 김
			right = mid - 1;	
		}
	}

	cout << ans;

	return 0;
}
