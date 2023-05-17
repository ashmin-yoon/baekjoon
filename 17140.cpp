#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 101;

int counting[MAX_SIZE]; // 각 숫자의 개수
int arr[MAX_SIZE][MAX_SIZE]; //  배열
int row, col;


int ROW, COL, K;

vector<pair<int, int> > v;

void Input() {
	cin >> ROW >> COL >> K;

	row = 3;
	col = 3;

	int value;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}
}


void InitCounting() {
	for (int i = 1; i <= 100; i++) {
		counting[i] = 0;
	}
}

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	// 등장 횟수 같음
	if (a.second == b.second) {
		return a.first < b.first;
	}

	return a.second < b.second;
}


// second 기준 오름차순
// second 같으면 first 오름차순
void SortVector() {
	sort(v.begin(), v.end(), cmp);
}

void InitRow(int r) {
	for (int c = 1; c <= col; c++) {
		arr[r][c] = 0;
	}
}

void InitCol(int c) {
	for (int r = 1; r <= row; r++) {
		arr[r][c] = 0;
	}
}

// 카운트 -> 배열로 변환
// 반환 값 = 배열 길이
int OperCountingToArr(int r, int c) {
	int length = 0;
	v.clear(); // 벡터 초기화

	// (수, 등장 횟수)
	for (int i = 1; i <= 100; i++) {
		if (counting[i] > 0) {
			v.push_back(make_pair(i, counting[i]));
		}
	}

	SortVector();

	// 카운트 초기화
	InitCounting();

	// 갱신될 (행 또는 열) 배열의 길이
	length = v.size() * 2; 
	if (length > 100)
		length = 100;

	// R 연산
	if (r != 0) {
		InitRow(r); // 초기화
		c = 1;

		for (int i = 0; i < v.size(); i++) {
			//printf("%d = %d회 등장\n", v[i].first, v[i].second);
			arr[r][c] = v[i].first;
			arr[r][c+1] = v[i].second;
			c += 2;
		}

	} // C 연산
	else if (c != 0) {
		InitCol(c);
		r = 1;

		for (int i = 0; i < v.size(); i++) {
			arr[r][c] = v[i].first;
			arr[r + 1][c] = v[i].second;
			r += 2;
		}

	}

	return length;
}

void OP_R() {
	int max_c = col;

	int value;
	for (int r = 1; r <= row; r++) {
		for (int c = 1; c <= col; c++) {
			value = arr[r][c];
			counting[value]++; // 카운트
		}

		max_c = max(max_c, OperCountingToArr(r, 0));
	}

	col = max_c;
}

void OP_C() {
	int max_r = row;

	int value;
	for (int c = 1; c <= col; c++) {
		for (int r = 1; r <= row; r++) {
			value = arr[r][c];
			counting[value]++; // 카운트
		}

		max_r = max(max_r, OperCountingToArr(0, c));
	}

	row = max_r;
}

void PrintArr(int time) {

	cout << "time = " << time << "=====================\n";
	for (int r = 1; r <= row; r++) {
		for (int c = 1; c <= col; c++) {
			cout << arr[r][c] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;
}

int Solution() {

	int time = 0;

	while (true) {
		if (time > 100) {
			return -1;
		}

		if (arr[ROW][COL] == K)
			break;

		if (row >= col) {
			OP_R();
		} else if (row < col) {
			OP_C();
		}


		time++;
		//PrintArr(time);
	}


	return time;
}

int main() {
	Input();
	cout << Solution();


	return 0;
}
