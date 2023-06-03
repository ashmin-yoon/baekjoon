#include <iostream>
using namespace std;
const int MAX_SIZE = 128;

int whiteCount;
int blueCount;

int N;

bool isBlue[MAX_SIZE][MAX_SIZE];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> isBlue[i][j];
		}
	}
}

void Divide(int startY, int startX, int length) {
	bool startIsBlue = isBlue[startY][startX];
	bool needDivision = false;

	for (int y = startY; y < startY + length; y++) {
		for (int x = startX; x < startX + length; x++) {	
			if (isBlue[y][x] != startIsBlue) {
				needDivision = true;
				break;
			}
		}
		if (needDivision)
			break;
	}

	// 색상 카운트
	if (needDivision == false)
	{
		if (isBlue[startY][startX])
			blueCount++;
		else
			whiteCount++;
		return;
	}

	// 분할
	int divLength = length / 2;
	Divide(startY, startX, divLength); // 좌상
	Divide(startY + divLength, startX, divLength); // 좌하
	Divide(startY, startX + divLength, divLength); // 우상
	Divide(startY + divLength, startX + divLength, divLength); // 우하
}

void Solution() {
	whiteCount = blueCount = 0;

	Divide(0, 0, N);

	cout << whiteCount << "\n";
	cout << blueCount << "\n";
}

int main() {
	FastIO();
	Input();
	Solution();

	return 0;
}
