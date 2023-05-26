#include <iostream>
#include <cmath>
using namespace std;

const int r = 31;
const int M = 1234567891;

int main() {
	int length;
	char ch;
	cin >> length;
	
	long long hash = 0;
	for (int i = 0; i < length; i++) {
		cin >> ch;

		// 제곱수
		long long remain = 1;
		for (int j = 0; j < i; j++) {
			remain = (remain * r) % M;
		}

		// 계산
		long long value = (ch - 'a' + 1) * remain;
		value %= M;
		hash += value;
		hash %= M;
	}

	cout << hash;


	return 0;
}
