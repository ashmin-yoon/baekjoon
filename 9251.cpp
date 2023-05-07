#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 1001;

int lcs[MAX_SIZE][MAX_SIZE];


// 오래 걸리고
// 사람들이 올린 반례를 기반으로 계속 수정했음
// 여전히 어렵다..


string str[2];

void Input() {
	cin >> str[0];
	cin >> str[1];
}

int Search(int first, int second) {
	int& ret = lcs[first][second];

	if (ret != -1) {
		return ret;
	}

	if (first == str[0].size() || second == str[1].size()) {
		ret = 0;
		return ret;
	}


	// 같음
	if (str[0][first] == str[1][second]) {
		ret = Search(first + 1, second + 1) + 1;
	}
	// 다름
	else {
		ret = max(ret, Search(first, second + 1));
		ret = max(ret, Search(first + 1, second));
	}

	return ret;
}


void Init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			lcs[i][j] = -1;
		}
	}
}

int main() {
	Init();
	Input();
	cout << Search(0, 0);

	return 0;
}
