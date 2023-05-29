#include <iostream>
using namespace std;
const int MAX_SIZE = 500;
const int MAX_HEIGHT = 256;

int land[MAX_SIZE][MAX_SIZE];
int N, M, B;
int TOTAL_BLOCK = 0;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> M >> B;
	TOTAL_BLOCK = B;

	for (int i = 0; i < N; i++) {
		for (int j = 0 ; j < M; j++) {
			cin >> land[i][j];
			TOTAL_BLOCK += land[i][j];
		}
	}
}

int MakeEqualHeigh(int height) {
	int exe_time = 0;

	// 불가능
	int neededBlockCnt = height * N * M;
	if (neededBlockCnt > TOTAL_BLOCK)
		return -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 블록 제거
			if (land[i][j] > height) {
				exe_time += 2 * (land[i][j] - height);
			}
			// 블록 채우기
			if (land[i][j] < height) {
				exe_time += (height - land[i][j]);
			}
		}
	}
	return exe_time;
}

void Solution() {

	int exe_time = 987654321;
	int height = -1;

	// 평탄화 작업
	for (int i = 0; i <= MAX_HEIGHT; i++) {
		int result_time = MakeEqualHeigh(i);
		if (result_time == -1)
			continue;

		// 시간이 짧은 것(동등 포함)
		if (result_time <= exe_time) {
			exe_time = result_time;
			height = i;
		}
	}

	cout << exe_time << " " << height;
}

int main() {

	FastIO();
	Input();
	Solution();


	return 0;
}
