#include <iostream>
using namespace std;

bool isEndNumber(int num) {
	int six_cnt = 0;

	while(num > 0) {
		if (num % 10 == 6)
			six_cnt++;
		else
			six_cnt = 0;
		num /= 10;

		if (six_cnt == 3)
			return true;
	}
	return false;
}

int main() {
	int N;
	cin >> N;

	int num = 666;
	int count = 0;
	while(num) {
		if (isEndNumber(num)) {
			count++;
		}

		if (count == N)
			break;

		num++;
	}

	cout << num;

	return 0;
}
