#include <iostream>

using namespace std;

// 최대 공약수
// 유클리드 호제법
int GCD(int a, int b) {
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	if (a == b || b == 0) {
		return a;
	}

	// r = a % b
	// GCD(a, b) = GCD(b, r);
	return GCD(b, a % b);
}

// 최소 공배수
int LCM(int a, int b) {
	int gcd = GCD(a, b);
	return a / gcd * b;
}

int main() {
	int n, m;
	cin >> n >> m;

	cout << GCD(n, m) << endl;
	cout << LCM(n, m) << endl;

	return 0;
}
