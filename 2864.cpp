#include <iostream>

using namespace std;

int GetMinNumber(int num) {
	int digit = 1;

	while(num / digit) {
		if (num / digit % 10== 6) {
			num -= digit;
		}

		digit *= 10;
	}

	return num;
}

int GetMaxNumber(int num) {
	int digit = 1;

	while(num / digit) {
		if (num / digit % 10 == 5) {
			num += digit;
		}
		digit *= 10;
	}

	return num;
}

int main() {

	int n1, n2;
	cin >> n1 >> n2;

	cout << GetMinNumber(n1) + GetMinNumber(n2) << " ";
	cout << GetMaxNumber(n1) + GetMaxNumber(n2) << endl;
	return 0;
}
