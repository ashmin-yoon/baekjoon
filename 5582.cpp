#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 4001;

string str1;
string str2;
int ans = 0;

int common_len[MAX_SIZE][MAX_SIZE];

// 내 풀이가 느렸던 원인
// dp 를 뒤쪽 방향으로 뒀는데
// 앞에서부터 진행해서 bottom up으로 해야함
// https://www.acmicpc.net/source/59573266

void Init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			common_len[i][j] = -1;
		}
	}
}


/*
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
	GetCommonLength(i, j + 1);

	ans = max(ans, ret); // 최대값 갱신
	return ret;
}
*/



int main() {
	cin >> str1;
	cin >> str2;


	//Init();
	// str1 순회
	/*
	for (int i = 0; i < str1.size(); i++) {
		GetCommonLength(i, 0);
	}
	*/


	// 1부터 시작
	// i - 1 최소 값이 0 되도록
	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				common_len[i][j] = common_len[i - 1][j - 1] + 1;
				ans = max(ans, common_len[i][j]);
			}
		}
	}

	cout << ans;

	return 0;
}
