#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX_SIZE = 300;
int arr[MAX_SIZE][MAX_SIZE];

int ROW;
int COL;
int R;

void RotateCounterclockwiseVectorVersion(int rotateCount) {
	int ringCount = min(ROW, COL) / 2;

	int tmpRotateCount = rotateCount;
	for (int rc = 0; rc < ringCount; rc++)
	{
		vector<int> v;
		rotateCount = tmpRotateCount;

		// [좌측 상단 ~ 우측 상단)
		for (int c = rc; c < COL - rc - 1; c++) {
			v.push_back(arr[rc][c]);
		}

		// [우측 상단 ~ 우측 하단)
		for (int r = rc; r < ROW - rc - 1; r++) {
			v.push_back(arr[r][COL-1-rc]);
		}

		// [우측 하단 ~ 좌측 하단)
		for (int c = COL - rc - 1; c > rc; c--) {
			v.push_back(arr[ROW-1-rc][c]);
		}

		// [좌측 하단 ~ 좌측 상단)
		for (int r = ROW - rc - 1; r > rc; r--) {
			v.push_back(arr[r][rc]);
		}

		// 순회 제거
		rotateCount %= v.size();

		// 회전용 데이터 추가
		for (int i = 0; i < rotateCount; i++) {
			v.push_back(v[i]);
		}

		int index = rotateCount;

		// [좌측 상단 ~ 우측 상단)
		for (int c = rc; c < COL - rc - 1; c++) {
			arr[rc][c] = v[index++];
		}

		// [우측 상단 ~ 우측 하단)
		for (int r = rc; r < ROW - rc - 1; r++) {
			arr[r][COL-1-rc] = v[index++];
		}

		// [우측 하단 ~ 좌측 하단)
		for (int c = COL - rc - 1; c > rc; c--) {
			arr[ROW-1-rc][c] = v[index++];
		}

		// [좌측 하단 ~ 좌측 상단)
		for (int r = ROW - rc - 1; r > rc; r--) {
			arr[r][rc] = v[index++];
		}
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> ROW >> COL >> R;
	// 반 시계 방향으로

	for (int r = 0; r < ROW; r++)
	{
		for (int c = 0; c < COL; c++) {
			cin >> arr[r][c];
		}
	}

	RotateCounterclockwiseVectorVersion(R);
	for (int r = 0; r < ROW; r++)
	{
		for (int c = 0; c < COL; c++) {
			cout << arr[r][c] << " ";
		}
		cout << "\n";
	}

	return 0;
}
