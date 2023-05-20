#include <iostream>

using namespace std;

int main() {

	int code = 0;
	int num;
	for (int i = 0; i < 5; i++) {
		cin >> num;
		code += num * num;
	}

	code %= 10;
	cout << code;



	return 0;
}
