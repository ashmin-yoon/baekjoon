#include <iostream>

using namespace std;

int main() {

	int input;
	cin >> input;

	int sum = 1;
	int i;
	for (i = 2; sum < input; i++) {
		sum += i;
	}
	i--;

	// 1열, 1행 부터 시작
	// i 행, 열에 사이 대각에 위치해 있음

	sum -= i; // 자리를 찾기 위해서
	int margin = input - sum;
	if (i % 2 == 0) {
		cout << margin << "/" << i - (margin - 1) << endl;
	} else {
		cout << i - (margin - 1) << "/" << margin << endl;
	}
	


	return 0;
}
