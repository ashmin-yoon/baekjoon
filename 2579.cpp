#include <iostream>
#include <algorithm>

using namespace std;

int stairs[301] = { 0 };
int value[301][2] = { 0 }; // value[][0] 전 칸, value[][1] 전전 칸

int main(int argc, char* argv[]) {

	int num = 0;
	cin >> num;

	for (int i = 1; i <= num; i++) {
		cin >> stairs[i];
	}

	// 초기값
	value[1][0] = stairs[1] + 0;
	value[1][1] = stairs[1] + 0;
	value[2][0] = stairs[2] + stairs[1]; 	// 자기 자신 + 전 칸
	value[2][1] = stairs[2] + 0;					// 자기 자신 + 전전 칸

	// 연속된 세 개의 계단 밟기 X
	for (int i = 3; i <= num; i++) {
		value[i][0] = stairs[i] + value[i-1][1]; // 전 칸을 밟고 올라온 현재 값 = 현재 계단 값 + 전 칸의 -2칸
		value[i][1] = stairs[i] + max(value[i-2][0], value[i-2][1]);
		// 전전 칸을 밟고 올라온 현재 값 = 현재 계단 값 + 전 칸의 (-1 칸, -2 칸 비교 후) 큰 값
	}

	/*
	cout << "계단\t계단값\t이전 칸\t전전 칸" << endl;
	for (int i = 1; i <= num; i++) {
		cout << i << "\t" << stairs[i] << "\t";
		for (int j = 0; j < 2; j++) {
			cout << value[i][j] << "\t";
		}
		cout << "\n";
	}
	*/

	// 마지막 계단은 꼭 밟아야 함
	cout << max(value[num][0], value[num][1]) << endl;


	return 0;
}
