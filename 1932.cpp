#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int result = 0;
	int num = 0;
	cin	>> num; 
	cout << "num : " << num << endl;

	const int ROW = num;
	const int COL = num + 1; // 일부러 한 칸 더 크게 생성
	cout << "ROW : " << ROW << ", " << "COL : " << COL << endl;

	// 동적 할당
	int** arr = new int * [ROW];

	for (int r = 0; r < ROW; r++) 
	{
		arr[r] = new int [COL]; 
	}


	// 초기화
	for (int r = 0; r < ROW; r++) {
		for (int c = 0; c < COL; c++) {
			arr[r][c] = 0;
		}
	}

	// 데이터 저장
	for (int r = 0; r < ROW; r++) {
		for (int c = 1; c < r + 2; c++) {
			cin >> arr[r][c];
		}
	}
	
	// 왼쪽 아래 대각 	= (row + 1, col)
	// 오른쪽 아래 대각 = (row + 1, col + 1)
	// 왼쪽 위 대각 	= r - 1, c - 1
	// 오른쪽 위 대각 = r - 1, c

	// 두번째 라인 부터 시작
	for (int r = 1; r < ROW; r++) {
		// 위 대각선 중 큰 값 추출
		for (int c = 1; c < COL; c++) {
			int value = max(arr[r - 1][c - 1], arr[r - 1][c]);
			arr[r][c] += value;
		}
	}
	
	// 최종 결과
	result = 0;
	for (int c = 1; c < COL; c++) {
		if (result < arr[ROW - 1][c])
			result = arr[ROW - 1][c];
	}
	cout << result;

	// 동적 할당 해제
	for (int r = 0; r < ROW; r++) {
		delete [] arr[r];
	}
	delete [] arr;
	return 0;	
}
