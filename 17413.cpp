#include <iostream>

using namespace std;

string ReverseStr(string str) {
	string result;
	//cout << "바꿀 단어 : " << str << endl;

	for (int i = 0; i < str.size(); i++) {
		result += str[str.size() - 1 - i];
	}

	return result;
}

int main() {
	string input;
	getline(cin, input);

	string ans = "";
	string tag_str;
	string normal_str;
	bool tag_mode = false;
	input += ' '; // 마지막 처리 편의를 위해 공백 추가
	
	for (int i = 0; i < input.size(); i++) {
		switch (input[i]) {
			case '<':
				ans += ReverseStr(normal_str); // 일반 단어 추가
				tag_mode = true;
				ans += '<';
				break;
			case '>':
				tag_mode = false;
				ans += tag_str;
				ans += '>';
				tag_str = ""; // 초기화
				normal_str = "";
				break;
			default:
				if (tag_mode) { // 태그 문자 일 때
					tag_str += input[i];
				} else if (input[i] == ' ') { // 태그 문자가 아닌데 공백일 
					ans += ReverseStr(normal_str);
					ans += ' ';
					normal_str = "";
				} else {
					normal_str += input[i];
				}
		}
	}

	for (int i = 0; i < ans.size() - 1; i++) {
		cout << ans[i];
	}
	cout << endl;

	return 0;
}
