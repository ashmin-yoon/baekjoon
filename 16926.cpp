#include <iostream>

using namespace std;

int row;
int col;
int rotation;
int ** arr;

void print(int r, int c) {
	//cout << "(" << r << ", " << c << ")" << endl;
}

void rotate(int i, int j) {
	int up_row = 0 + i;					// 윗 행
	int down_row = row - 1 - i;	// 아래 행
	int left_col = 0 + j;				// 좌측 열
	int right_col = col - 1 - j;// 우측 열
	

	// 몇 칸을 이동 시켜야 하는지
	int r_count = row - 2 * j;
	int c_count = col - 2 * i;
	
	int curr_row;
	int curr_col;
	int tmp = arr[down_row][left_col];

	// 각 칸 접근
	// 왼쪽 열 부터
	for (int r = 0; r < r_count - 1; r++) {
		// 다음 값 저장
		curr_row = down_row - r;
		arr[curr_row][left_col] = arr[curr_row - 1][left_col]; // 현재 칸 = 이전 칸
		print(curr_row, left_col);
	}

	// 윗 행
	for (int c = 0; c < c_count - 1; c++) {
		curr_col = left_col + c;
		arr[up_row][curr_col] = arr[up_row][curr_col + 1];
		print(up_row, curr_col);
	}
	
	// 오른쪽 열
	for (int r = 0; r < r_count - 1; r++) {
		curr_row = up_row + r;
		arr[curr_row][right_col] = arr[curr_row + 1][right_col];
		print(curr_row, right_col);
	}

	// 아래 행
	for (int c = 0; c < c_count - 1; c++) {
		curr_col = right_col - c;
		arr[down_row][curr_col] = arr[down_row][curr_col - 1]; // 현재 칸 = 이전 칸
		print(down_row, curr_col);
	}
	
	arr[down_row][curr_col] = tmp;
}


int main() {
	
	cin >> row;
	cin >> col;
	cin >> rotation;

	// 동적 할당
	arr = new int * [row];
	for (int i = 0; i < row; i++) {
		arr[i] = new int [col];
	}

	// 값 입력
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			cin >> arr[r][c];
		}
	}

	int i_count = row/2;
	int j_count = col/2;


	int i = 0;
	int j = 0;
	// 테두리 범위 지정
	// i 값과 j 값을 넘겨주면
	// 함수에서 처리
	while(rotation--) {
		i = 0;
		j = 0;
		while (i < i_count && j < j_count) {
			rotate(i, j);
			i++;
			j++;
		}
	}

	// 출력
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col - 1; c++) {
			cout << arr[r][c] << " ";
		}
		cout << arr[r][col - 1];
		cout << endl;
	}



	// 동적 할당 메모리 삭제
	for (int i = 0; i < row; i++) {
		delete [] arr[i];
	}
	delete [] arr;

	return 0;
}
