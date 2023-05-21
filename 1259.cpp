#include <iostream>
using namespace std;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

bool isPalindrome(string str) {
	int left = 0;
	int right = str.size() - 1;

	while(left < right) {
		if (str[left] != str[right]) {
			return false;
		}

		// eq
		left++;
		right--;
	}
	return true;
}

int main() {
	FastIO();

	string str;
	while(true) {
		cin >> str;
		if (str == "0")
			break;

		if(isPalindrome(str)) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}

}
