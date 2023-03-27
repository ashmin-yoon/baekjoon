#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	int num;
	string str;

	while(T--) {
		cin >> num;
		cin >> str;

		for (int i = 0; i < str.size(); i++) {
			for (int j = 0; j < num; j++) {
				cout << str[i];
			}
		}

	}

	return 0;
}
