#include <iostream>
#include <algorithm>

int value[1000][3] = { 0 };

using namespace std;
int get_previous_min_value(int current_row, int current_col) {
	
	int min_value;
	int pre_r = current_row - 1;

	// 현재의 색과 다른 색을 기준으로 골라야 함
	switch(current_col)
	{
		case 0:
			min_value = min(value[pre_r][1], value[pre_r][2]);
			break;
		case 1:
			min_value = min(value[pre_r][0], value[pre_r][2]);
			break;
		case 2:
			min_value = min(value[pre_r][0], value[pre_r][1]);
			break;
	}	
	
	return min_value;
}

int main(int argc, char* argv[]) {

	int n;
	int result;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> value[i][j];
		}	
	}

	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cout << value[i][j] << "\t";
		}	
		cout << endl;
	}
	*/

	// 2번째 부터 시작( 인덱스 1 )
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			value[i][j] += get_previous_min_value(i, j);
		}	
	}

	result = min(min(value[n-1][0], value[n-1][1]), value[n-1][2]);
	cout << result << endl;
	return 0;
}
