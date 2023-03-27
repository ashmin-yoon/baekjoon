#include <iostream>

using namespace std;

int main() {
	string str;

	cin >> str;

	int zero_str_count = 0;
	int one_str_count = 0;
	char pre_char = '-';

	for (int i = 0; i < str.length(); i++) {
		if(str[i] == '1') {
			if (pre_char != str[i])
				one_str_count++;
			pre_char = '1';
			continue;
		}

		if (pre_char != str[i])
			zero_str_count++;
		pre_char = '0';
	}


	int result = zero_str_count < one_str_count 
		? zero_str_count : one_str_count;

	cout << result << endl;


	return 0;
}
