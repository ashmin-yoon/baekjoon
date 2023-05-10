#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 4000;

string str1;
string str2;
int ans = 0;

int common_len[MAX_SIZE][MAX_SIZE];

void Init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			common_len[i][j] = -1;
		}
	}
}


int GetCommonLength(int i, int j) {
	if (i == str1.size() || j == str2.size()) {
		return 0;
	}

	int& ret = common_len[i][j];

	// 이미 구함
	if (ret != -1) {
		return ret;
	}


	// 문자 같음
	if (str1[i] == str2[j]) {
		ret = 1 + GetCommonLength(i + 1, j + 1); // 현재 = 다음 + 1
	}
	
	// 문자 다름
	else {
		ret = 0; // 현재 = 0
	}

	// 같던 다르던 다음 진행
	GetCommonLength(i + 1, j);
	GetCommonLength(i, j + 1);

	ans = max(ans, ret); // 최대값 갱신
	return ret;
}


int main() {
	cin >> str1;
	cin >> str2;

	Init();
	GetCommonLength(0, 0);
	cout << ans;

	return 0;
}
