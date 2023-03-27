#include <iostream>

using namespace std;

void PrintStar(int num) {
	for (int i = 0; i < num; i++) {
		cout << "*";
	}
	cout << endl;
}

int main() {
	int num = 0;
	cin >> num;

	for (int i = 1; i <= num; i++) {
		PrintStar(i);
	}

	return 0;
}
