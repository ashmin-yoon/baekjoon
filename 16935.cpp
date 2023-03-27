#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

int N;
int M;
int arr[MAX_SIZE][MAX_SIZE];
int COL;
int ROW;

void UpAndDownInversion() {
	int tmp;
	for (int r = 0; r < ROW/2; r++)
	{
		for (int c = 0; c < COL; c++)
		{
			tmp = arr[r][c];
			arr[r][c] = arr[ROW-1-r][c];
			arr[ROW-1-r][c] = tmp;
		}
	}
}

void LeftAndRightInversion() {
	int tmp;
	for (int c = 0; c < COL/2; c++)
	{
		for (int r = 0; r < ROW; r++)
		{
			tmp = arr[r][c];
			arr[r][c] = arr[r][COL-1-c];
			arr[r][COL-1-c] = tmp;
		}
	}
}

void Turn90DegreesClockwise() {
	int** tmpArr = new int * [ROW];
	for (int r = 0; r < ROW; r++) {
		tmpArr[r] = new int [COL];
		for (int c = 0; c < COL; c++) {
			tmpArr[r][c] = arr[r][c];
		}
	}

	for (int r = 0; r < ROW; r++) {
		for (int c = 0; c < COL; c++) {
			arr[c][ROW-1-r] = tmpArr[r][c];
		}	
	}

	for (int r = 0; r < ROW; r++)
		delete [] tmpArr[r];
	delete [] tmpArr;

	int tmp;
	tmp = COL;
	COL = ROW;
	ROW = tmp;
}

void Turn90DegreesCounterclockwise() {
	int** tmpArr = new int * [ROW];
	for (int r = 0; r < ROW; r++) {
		tmpArr[r] = new int [COL];
		for (int c = 0; c < COL; c++) {
			tmpArr[r][c] = arr[r][c];
		}
	}

	for (int r = 0; r < ROW; r++) {
		for (int c = 0; c < COL; c++) {
			arr[COL-1-c][r] = tmpArr[r][c];
		}	
	}

	for (int r = 0; r < ROW; r++)
		delete [] tmpArr[r];
	delete [] tmpArr;

	int tmp;
	tmp = COL;
	COL = ROW;
	ROW = tmp;
}

void cmd5() {
	int miniROW = ROW / 2;
	int miniCOL = COL / 2;
	
	int tmp;

	// 1->2->3->4->1
	for (int i = 0; i < miniROW; i++) {
		for (int j = 0; j < miniCOL; j++) {
			// 4번 저장
			tmp = arr[miniROW+i][j];

			// 4번 = 3번
			arr[miniROW+i][j] =	arr[miniROW+i][miniCOL+j];

			// 3번 = 2번
			arr[miniROW+i][miniCOL+j] = arr[i][miniCOL+j];

			// 2번 = 1번
			arr[i][miniCOL+j] = arr[i][j];

			// 1번 = 4번
			arr[i][j] = tmp;
		}
	}
}

void cmd6() {
	int miniROW = ROW / 2;
	int miniCOL = COL / 2;
	int tmp;

	// 1->4->3->2->1
	for (int i = 0; i < miniROW; i++) {
		for (int j = 0; j < miniCOL; j++) {
			// 2번 저장
			tmp = arr[i][miniCOL+j];

			// 2번 = 3번
			arr[i][miniCOL+j] = arr[miniROW+i][miniCOL+j];

			// 3번 = 4번
			arr[miniROW+i][miniCOL+j] = arr[miniROW+i][j];

			// 4번 = 1번
			arr[miniROW+i][j] = arr[i][j];

			// 1번 = 2번
			arr[i][j] = tmp;
		}
	}

}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	ROW = N;
	COL = M;

	int cmdCount = 0;
	cin >> cmdCount;

	int** board = new int * [N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < cmdCount; i++)
	{
		int cmd;
		cin >> cmd;
		switch(cmd)
		{
			case 1:
				// 상하 반전
				UpAndDownInversion();
				break;
			case 2:
				// 좌우 반전
				LeftAndRightInversion();
				break;
			case 3:
				// 오른쪽으로 90도
				Turn90DegreesClockwise();
				break;
			case 4:
				// 왼쪽으로 90도
				Turn90DegreesCounterclockwise();
				break;
			case 5:
				cmd5();
				break;
			case 6:
				cmd6();
				break;
		}

	}

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

		return 0;
}
