#include <iostream>

using namespace std;

string ChangeString(int count) {
	string str = "";
	if (count % 2 != 0) {
		cout << "-1";
		exit(0);
	}

	for (int i = 0; i < (count / 4); i++) {
		str += "AAAA";
	}

	for (int i = 0; i < (count % 4 / 2); i++) {
		str += "BB";
	}

	return str;
}
int main() {
	string str = "";
	string result = "";

	cin >> str;
	int count = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '.') {	
			result += ChangeString(count);
			result += ".";
			count = 0;
			continue;
		}

		count++;
	}

	result += ChangeString(count);

	cout << result << endl;
	return 0;
}
