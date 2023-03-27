#include <iostream>

using namespace std;

bool flag[10001];

int digit_sum(int num) {
	int sum = 0;
	while(num) {
		sum += num % 10;	
		num = num/10;
	}
	return sum;
}

void func(int num) {
	if (flag[num] || num > 10000)
		return;

	flag[num] = true;
	num = num + digit_sum(num);
	func(num);
}

int main() {
	for (int i = 1; i <= 10000; i++) {
		if (flag[i] == false)
			cout << i << endl;
		func(i);
	}


	return 0;
}
