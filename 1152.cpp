#include <iostream>

using namespace std;

int main() {

	string str;

	getline(cin, str);	 // 공백 포함 문자열 일 때는 getline 으로 받아야 함

	int count = 1; // 공백 하나당 단어 두 개
	for (int i = 0; i < str.length(); i++) {
		//cout << "str[" << i << "] = " << str[i] << endl;
		if(str[i] == ' ')
			count++;
	}

	if(str[0] == ' ')
		count--;
	if(str[str.length() - 1] == ' ')
		count--;

	cout << count;
	return 0;
}
