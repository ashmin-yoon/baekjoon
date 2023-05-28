#include <iostream>
#include <vector>
using namespace std;

vector<char> v;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

bool validate(string& str) {
	v.clear();
	char ch;
	for (int i = 0; i < str.size(); i++) {
		ch = str[i];

		if (ch == '[' || ch == '(') {
			v.push_back(ch);
		}

		else if (ch == ']') {
			if (v.size() == 0 || v.back() != '[')
				return false;
			v.pop_back();
		}

		else if (ch == ')') {
			if (v.size() == 0 || v.back() != '(')
				return false;
			v.pop_back();
		}
	}

	if (v.size())
		return false;
	return true;
}


int main() {

	FastIO();
	string str;

	while(1) 
	{
		getline(cin, str);

		if (validate(str)) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}

		if (str == ".") {
			break;
		}
	}

	return 0;
}
