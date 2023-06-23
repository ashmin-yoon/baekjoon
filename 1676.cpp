#include <iostream>

int N;

using namespace std;

int Solution() {

	int zero_cnt = 0;
	int two_cnt = 0;
	int five_cnt = 0;

	for (int i = 2; i <= N; i++) {
		int num = i;

		// 2 소인수 분해
		while (num % 2 == 0) {
			two_cnt++;
			num /= 2;
		}
		
		// 5 소인수 분해
		while (num % 5 == 0) {
			five_cnt++;
			num /= 5;
		}
	}

	zero_cnt = five_cnt;
	return zero_cnt;
}

int main() {
	cin >> N;
	cout << Solution();

	return 0;
}
