#include <iostream>

using namespace std;

int GetValue(int num) {
	int ret = num;

	while (num > 0) {
		ret += (num % 10);
		num /= 10;
	}
	return ret;
}

int main() {
	int N, M;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		//cout << i << " = " << GetValue(i) << "\n";
		if (GetValue(i) == N) {
			cout << i;
			return 0;
		}
	}

	cout << 0;
	return 0;

}
