#include <iostream>
using namespace std;

int N, K;

int main() {
	cin >> N >> K;

	int ans = 1;

	// ans = N! / K!
	for (int i = N; i > K; i--) {
		ans *= i;
	}

	// ans /= (n - k)!
	for (int i = N - K; i >= 1; i--) {
		ans /= i;
	}

	cout << ans;

	return 0;
}
