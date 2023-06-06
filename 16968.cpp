#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	int ans = 0;

	if (str[0] == 'c')
		ans = 26;
	if (str[0] == 'd')
		ans = 10;

	for (int i = 1; i < str.size(); i++) {
		// 이전과 같음
		if (str[i] == str[i - 1]) {
			if (str[i] == 'c')
				ans *= 25;
			if (str[i] == 'd')
				ans *= 9;
		}

		else {
			// 이전과 다름
			if (str[i] == 'c')
				ans *= 26;
			if (str[i] == 'd')
				ans *= 10;
		}
	}

	cout << ans;

	return 0;
}
