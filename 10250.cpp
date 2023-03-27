#include <iostream>

using namespace std;

int main() {

	int T;
	int H, W;
	int N;

	cin >> T;
	while(T--) {
		cin >> H >> W;
		cin >> N;

		if (H == 1) {
			cout << 1;
			if (N < 10)
				cout << 0;
			cout << N << endl;
			continue;
		}

		int floor = N % H;
		int number = N / H + 1;
		if (N % H == 0) {
			floor = H;
			number = N / H;
		}
		cout << floor;
		if (number < 10) {
			cout << 0;
		}
		cout << number << endl;
	}



	return 0;
}
