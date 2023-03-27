#include <iostream>

using namespace std;

int count_arr[26];

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < 26; i++) {
		count_arr[i] = 0;
	}

	for (int i = 0; i < str.size(); i++) {
		count_arr[tolower(str[i]) - 'a']++;
		cout << (char)tolower(str[i]);
	}
	cout << endl;

	int max = -1;
	int max_index = -1;
	for (int i = 0; i < 26; i++) {
		if (max < count_arr[i]) {
			max = count_arr[i];
			max_index = i;
		}
		else if (max == count_arr[i]) {
			max_index = -1;
		}
	}

	if (max_index == -1)
		cout << "?" << endl;
	else
		cout << (char)('A' + max_index) << endl;


	return 0;
}
