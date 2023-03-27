#include <iostream>
#include <vector>

using namespace std;


int main() {
	int num;

	cin >> num;

	vector<string> text;

	for (int i = 0; i < num; i++) {
		string str;
		cin >> str;
		text.push_back(str);
	}

	string answer = text[0];

	for (int i = 0; i < text[0].size(); i++) {
		char ch = text[0][i];
		// 첫번째 텍스트의 i 위치에 있는 문자와
	 	// 전체의 i위치 문자 비교
		for (int j = 0; j < num; j++) {
			if (ch != text[j][i])
				answer[i] = '?';
		}
	}

	cout << answer << endl;

	return 0;
}
