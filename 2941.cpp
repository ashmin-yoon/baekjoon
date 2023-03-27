#include <iostream>
#include <string>

using namespace std;

int find_str_count[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
string find_str[8];

// 참조 : https://velog.io/@kjpark4321/%EC%BD%94%ED%85%8C-%EB%8C%80%EB%B9%84-c-%EB%AC%B8%EC%9E%90%EC%97%B4-%EC%B2%98%EB%A6%AC-2-ReplaceAll 
int Solution(string& str) {
	size_t start_pos = 0;
	size_t tmp_pos = 0;
	int count = 0;

	for (int i = 0; i < 8; i++) {
		start_pos = 0;
		while(true) {
			start_pos = str.find(find_str[i], start_pos);
			if (start_pos == string::npos) {
				break;
			}

			find_str_count[i]++;
			start_pos += find_str[i].length();
			//cout << start_pos << endl;

		}
		//cout << find_str_count[i] << endl;
	}

	return count;
}


int main() {

	int count = 0;
	string str;
	cin >> str;

	int result = str.size();
	find_str[0] = "c=";
	find_str[1] = "c-";
	find_str[2] = "dz=";
	find_str[3] = "d-";
	find_str[4] = "lj";
	find_str[5] = "nj";
	find_str[6] = "s=";
	find_str[7] = "z=";

	Solution(str);

	// [2]가 있으면 [7] 도 중복해서 있음
	if (find_str_count[2])
		find_str_count[7] -= find_str_count[2];

	for (int i = 0; i < 8; i++) {
		result -= find_str_count[i] * ((int)find_str[i].size() - 1);
	}
	cout << result;

	return 0;
}
