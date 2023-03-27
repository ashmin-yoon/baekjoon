#include <iostream>

using namespace std;

int main() {
	int num;
	int count = 0;
	cin >> num;
	int target = num;

	do {
		int sum = (num / 10 + num % 10) % 10;
		num = num % 10 * 10 + sum;
		count++;
	}
	while (target != num);

	cout << count << endl;
	

	return 0;
}
