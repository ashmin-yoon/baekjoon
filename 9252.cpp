#include <iostream>
using namespace std;
const int MAX_SIZE = 1001;

// string 으로 했을 경우 시간 초과

typedef struct Data {
	char ch;
	int length;
	int next_i;
	int next_j;
	Data() {
		length = 0;
		ch = '\0';
	}
	Data(char ch, int length, int i, int j) :
		ch(ch), length(length), next_i(i), next_j(j) {}
}Data;

Data lcs[MAX_SIZE][MAX_SIZE];


string str1;
string str2;

void Init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			lcs[i][j] = Data('\0', -1, -1, -1); 
		}
	}
}

Data FindLCS(int first, int second) {

	Data& ret = lcs[first][second];

	// isFound
	if (ret.length != -1) {
		return ret;
	}

	// last
	if (first == str1.size() || second == str2.size()) {
		ret.length = 0;
		return ret;
	}

	// 같은 문자
	if (str1[first] == str2[second]) {
		ret.ch = str1[first];
		ret.next_i = first + 1;
		ret.next_j = second + 1;

		Data result = FindLCS(first + 1, second + 1);
		ret.length = result.length + 1;
		return ret;
	}

	// 다른 문자
	Data result1 = FindLCS(first + 1, second);
	Data result2 = FindLCS(first, second + 1);


	// 갱신
	if (result1.length > ret.length) {
		ret.ch = result1.ch;
		ret.length = result1.length;
		ret.next_i = first + 1;
		ret.next_j = second;
	}

	// 갱신
	if (result2.length > ret.length) {
		ret.ch = result2.ch;
		ret.length = result2.length;
		ret.next_i = first;
		ret.next_j = second + 1;
	}

	return ret;
}

int main() {
	Init();
	cin >> str1;
	cin >> str2;

	Data ans = FindLCS(0, 0);

	// 길이
	cout << ans.length << "\n";

	int length = ans.length;
	int pre_l = 0;
	int i = 0, j = 0;
	while(length > 0) {
		Data& ret = lcs[i][j];
		length = ret.length;
		
		if (pre_l != length) {
			cout << ret.ch;
		}

		i = ret.next_i;
		j = ret.next_j;
		pre_l = length;
	}

	return 0;
}
