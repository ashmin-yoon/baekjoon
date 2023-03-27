#include <iostream>
#include <vector>

// 해석 및 풀이 참고
// https://brightmango.tistory.com/346

using namespace std;

int main() {
	int n, sum = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		sum += n / i * i;
	}
	cout << sum << endl;
	return 0;
}
