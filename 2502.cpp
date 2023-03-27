#include <iostream>

using namespace std;

int day[31];
int fibo_arr[31] = { 0, 1, 1 };

void fibo_setting(int n) {
	for (int i = 3; i <= n; i++) {
		fibo_arr[i] = fibo_arr[i - 1] + fibo_arr[i - 2];
	}
}

int main(int argc, char* argv[]) {

	int d, k;

	cin >> d >> k;
	fibo_setting(30);

	day[d] = k;

	int a_value = fibo_arr[d - 2]; 	// a 계수
	int b_value = fibo_arr[d - 1];	// b 계수

	//cout << "a계수 = " << a_value << endl;
	//cout << "b계수 = " << b_value << endl;

	int a, b;

	for (int i = 0; i * a_value < k; i++) {
		for (int j = 0; j * b_value < k; j++) {
			a = i * a_value;
			b = j * b_value;

			if ((a + b) == k) {
				cout << i << endl;
				cout << j << endl;
				return 0;
			}
		}
	}
	return 0;
}
