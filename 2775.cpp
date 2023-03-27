#include <iostream>

using namespace std;

int apartment[15][15];

int GetNum(int i, int j) {
	int sum = 0;
	for (int tmp = 1; tmp <= j; tmp++) {
		sum += apartment[i-1][tmp];
	}
	return sum;
}

int main() {

	int Case;
	int floor; // 층
	int number;// 호수

	// 호수는 index 1 부터
	for (int i = 0; i < 15; i++) {
		apartment[0][i] = i;
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			apartment[i][j] = GetNum(i, j);
		}
	}

	cin >> Case;
	while(Case--) {
		cin >> floor >> number;
		cout << apartment[floor][number] << endl;
	}

	return 0;
}
